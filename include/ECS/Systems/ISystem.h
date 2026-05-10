#pragma once
#include <bitset>

#include "../Components.h"
#include "../Registry.h"

namespace MyGame::ECS::Systems {

    class ISystem {
    protected:
        std::bitset<Components::MAX_COMPONENTS> requiredMask;
    public:
        virtual void update(Registry& registry, float dt) = 0;
        virtual ~ISystem() = default;
    };

}
