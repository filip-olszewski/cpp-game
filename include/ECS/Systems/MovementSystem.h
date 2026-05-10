#pragma once
#include "ISystem.h"

namespace MyGame::ECS::Systems {

    class MovementSystem : public ISystem {
    public:
        MovementSystem();
        void update(Registry& registry, float dt) override;
    };

}
