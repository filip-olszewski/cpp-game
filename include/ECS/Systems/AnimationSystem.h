#pragma once
#include "ISystem.h"

namespace MyGame::ECS::Systems {

    class AnimationSystem : public ISystem {
    public:
        AnimationSystem();
        void update(Registry &registry, float dt) override;
    };
}
