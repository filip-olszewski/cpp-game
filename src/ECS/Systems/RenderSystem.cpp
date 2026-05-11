#include "../../../include/ECS/Systems/RenderSystem.h"

namespace MyGame::ECS::Systems {

    RenderSystem::RenderSystem(sf::RenderWindow& window)
        : window(window) {
        requiredMask.set(Components::ComponentManager::getId<Components::Render>());
        requiredMask.set(Components::ComponentManager::getId<Components::Position>());
    }

    void RenderSystem::update(Registry &registry, float dt) {
        for (Entity e = 0; e < registry.getEntityCount(); ++e) {
            if (!registry.hasComponents(e, requiredMask)) {
                continue;
            }

            Components::Render& render = registry.getComponent<Components::Render>(e);
            Components::Position& position = registry.getComponent<Components::Position>(e);

            if (!render.texture) continue;

            sf::Sprite sprite(*render.texture);
            sprite.setPosition({position.x, position.y});

            if (render.rect.size.x > 0 && render.rect.size.y > 0) {
                sprite.setTextureRect(render.rect);
            }

            window.draw(sprite);
        }
    }

}
