#include "../../../include/ECS/Systems/MovementSystem.h"

namespace MyGame::ECS::Systems {

    MovementSystem::MovementSystem() {
        requiredMask.set(Components::ComponentManager::getId<Components::Position>());
        requiredMask.set(Components::ComponentManager::getId<Components::Velocity>());
        requiredMask.set(Components::ComponentManager::getId<Components::Input>());
    }

    void MovementSystem::update(Registry &registry, float dt) {
        for (Entity e = 0; e < registry.getEntityCount(); ++e) {
            if (!registry.hasComponents(e, requiredMask)) {
                continue;
            }

            auto& pos = registry.getComponent<Components::Position>(e);
            auto& velocity = registry.getComponent<Components::Velocity>(e);

            pos.x = pos.x + velocity.vx * dt;
            pos.y = pos.y + velocity.vy * dt;
        }
    }
}
