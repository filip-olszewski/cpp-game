#pragma once
#include "ISystem.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace MyGame::ECS::Systems {

    class RenderSystem : public ISystem {
        sf::RenderWindow& window;
    public:
        explicit RenderSystem(sf::RenderWindow& window);
        void update(Registry &registry, float dt) override;
    };

}
