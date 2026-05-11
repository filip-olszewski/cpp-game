#include "../../../include/ECS/Systems/PlayerControlSystem.h"

namespace MyGame::ECS::Systems {

    PlayerControlSystem::PlayerControlSystem() {
        requiredMask.set(Components::ComponentManager::getId<Components::Input>());
        requiredMask.set(Components::ComponentManager::getId<Components::Velocity>());
    }

    void PlayerControlSystem::update(Registry &registry, float dt) {
        for (Entity e = 0; e < registry.getEntityCount(); ++e) {
            if (!registry.hasComponents(e, requiredMask)) {
                continue;
            }

            auto& velocity = registry.getComponent<Components::Velocity>(e);
            auto& input = registry.getComponent<Components::Input>(e);

            velocity.vx = 0;
            velocity.vy = 0;

            if (input.keyUp) velocity.vy -= velocity.speed;
            if (input.keyDown) velocity.vy += velocity.speed;
            if (input.keyLeft) velocity.vx -= velocity.speed;
            if (input.keyRight) velocity.vx += velocity.speed;
        }
    }
}
