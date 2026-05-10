#include "../../include/Core/Game.h"

namespace MyGame::Core {

    Game::Game()
        : window(sf::VideoMode::getDesktopMode(), Constants::WINDOW_TITLE.data()) {
        window.setFramerateLimit(Constants::MAX_FPS);

        systems.push_back(std::make_unique<ECS::Systems::MovementSystem>());
        systems.push_back(std::make_unique<ECS::Systems::RenderSystem>(window));

        player = registry.createEntity();
        registry.addPosition(player, ECS::Components::Position{100, 100});
        ECS::Components::Sprite sprite;
        sprite.sprite.setSize({100, 100});
        sprite.sprite.setFillColor(sf::Color::Red);
        registry.addSprite(player, sprite);
    }

    void Game::init() {
        isRunning = true;
        clock.start();

        while (isRunning && window.isOpen()) {

            float dt = clock.restart().asSeconds();

            handleEvents();
            handleInput();

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

    void Game::handleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape)) {
            shutdown();
        }
    }

    void Game::shutdown() {
        isRunning = false;
        window.close();
    }

}
