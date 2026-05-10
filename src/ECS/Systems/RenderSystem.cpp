#include "../../../include/ECS/Systems/RenderSystem.h"

namespace MyGame::ECS::Systems {

    RenderSystem::RenderSystem(sf::RenderWindow& window)
        : window(window) {
        requiredMask.set(Components::typeToId(Components::Type::SPRITE));
        requiredMask.set(Components::typeToId(Components::Type::POSITION));
    }

    void RenderSystem::update(Registry &registry, float dt) {
        for (Entity e = 0; e < registry.getEntityCount(); ++e) {
            if (!registry.hasComponents(e, requiredMask)) {
                continue;
            }

            Components::Sprite& sprite = registry.getSprite(e);
            Components::Position& position = registry.getPosition(e);

            sprite.sprite.setPosition({position.x, position.y});
            window.draw(sprite.sprite);
        }
    }

}
