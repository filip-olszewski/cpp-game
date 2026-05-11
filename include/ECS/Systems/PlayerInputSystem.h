#pragma once
#include "ISystem.h"

namespace MyGame::ECS::Systems {

    class PlayerInputSystem : public ISystem {
    public:
        PlayerInputSystem();
        void update(Registry &registry, float dt) override;
    };

}
