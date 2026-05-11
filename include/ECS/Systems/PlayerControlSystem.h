#pragma once
#include "ISystem.h"


namespace MyGame::ECS::Systems {

    class PlayerControlSystem : public ISystem {
    public:
        PlayerControlSystem();
        void update(Registry &registry, float dt) override;
    };

}
