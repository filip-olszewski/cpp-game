#include "../../include/Core/Game.h"

namespace MyGame::Core {

    Game::Game()
        : window(sf::VideoMode::getDesktopMode(), Constants::WINDOW_TITLE.data()) {
        window.setFramerateLimit(Constants::MAX_FPS);

        systems.push_back(std::make_unique<ECS::Systems::PlayerInputSystem>());
        systems.push_back(std::make_unique<ECS::Systems::PlayerControlSystem>());
        systems.push_back(std::make_unique<ECS::Systems::MovementSystem>());
        systems.push_back(std::make_unique<ECS::Systems::RenderSystem>(window));
        systems.push_back(std::make_unique<ECS::Systems::AnimationSystem>());

        player = registry.createEntity();

        sf::Texture& playerTex = assetManager.addTexture("player", "assets/Cute_Fantasy_Free/Player/Player.png");

        ECS::Components::Render renderComponent{playerTex, sf::IntRect({0,0}, {32, 32})};
        registry.addComponent<ECS::Components::Render>(player, renderComponent);

        ECS::Components::Animation animationComponent{6, 0};
        registry.addComponent<ECS::Components::Animation>(player, animationComponent);

        ECS::Components::Position positionComponent = { 100, 100 };
        registry.addComponent<ECS::Components::Position>(player, positionComponent);

        ECS::Components::Velocity velocityComponent{};
        registry.addComponent<ECS::Components::Velocity>(player, velocityComponent);

        ECS::Components::Input inputComponent{};
        registry.addComponent<ECS::Components::Input>(player, inputComponent);
    }

    void Game::init() {
        isRunning = true;
        clock.start();

        while (isRunning && window.isOpen()) {

            float dt = clock.restart().asSeconds();

            handleEvents();

            window.clear();
            update(dt);
            window.display();
        }
    }

    void Game::update(float dt) {
        for (const auto& system : systems) {
            system->update(registry, dt);
        }
    }

    void Game::handleEvents() {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                shutdown();
            }
        }
    }

    void Game::shutdown() {
        isRunning = false;
        window.close();
    }

}
