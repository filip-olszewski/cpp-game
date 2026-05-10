#include "../../../include/ECS/Systems/MovementSystem.h"

namespace MyGame::ECS::Systems {

    MovementSystem::MovementSystem() {
        requiredMask.set(Components::typeToId(Components::Type::POSITION));
        requiredMask.set(Components::typeToId(Components::Type::VELOCITY));
    }

    void MovementSystem::update(Registry &registry, float dt) {
        for (Entity e = 0; e < registry.getEntityCount(); ++e) {
            if (!registry.hasComponents(e, requiredMask)) {
                continue;
            }

            Components::Position& pos = registry.getPosition(e);
            Components::Velocity& velocity = registry.getVelocity(e);

            pos.x = velocity.vx * dt;
            pos.y = velocity.vy * dt;
        }
    }
}
