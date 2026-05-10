#pragma once
#include <stack>
#include <SFML/Graphics.hpp>

#include "../../include/Core/Constants.h"
#include "IScene.h"
#include "../ECS/Systems/ISystem.h"
#include "../ECS/Systems/RenderSystem.h"
#include "../ECS/Systems/MovementSystem.h"

namespace MyGame::Core {

    class Game {
        bool isRunning = false;
        sf::RenderWindow window;
        sf::Clock clock;
        std::vector<std::unique_ptr<ECS::Systems::ISystem>> systems;
        ECS::Registry registry;
        ECS::Entity player;

        void update(float dt);
        void handleEvents();
        void handleInput();
        void shutdown();
    public:
        Game();
        void init();
    };

}

