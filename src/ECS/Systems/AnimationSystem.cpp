#include "../../../include/ECS/Systems/AnimationSystem.h"

#include <iostream>

namespace MyGame::ECS::Systems {

    AnimationSystem::AnimationSystem() {
        requiredMask.set(Components::ComponentManager::getId<Components::Render>());
        requiredMask.set(Components::ComponentManager::getId<Components::Animation>());
    }

    void AnimationSystem::update(Registry &registry, float dt) {
        for (Entity e = 0; e < registry.getEntityCount(); ++e) {
            if (!registry.hasComponents(e, requiredMask)) {
                continue;
            }

            auto& renderComp = registry.getComponent<Components::Render>(e);
            auto& animationComp = registry.getComponent<Components::Animation>(e);

            animationComp.accumulator += dt;
            if (animationComp.accumulator < animationComp.animationSpeed) continue;

            animationComp.accumulator -= animationComp.animationSpeed;

            animationComp.currentFrame = (animationComp.currentFrame + 1) % animationComp.frameCount;
            renderComp.rect.position.x = (renderComp.rect.size.x + animationComp.frameGap) * animationComp.currentFrame;
        }
    }
}
