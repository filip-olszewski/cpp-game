#pragma once
#include <vector>

#include "IPool.h"

namespace MyGame::ECS {

    template <typename T>
    class ComponentPool : public IPool {
    public:
        std::vector<T> components;

        explicit ComponentPool(std::size_t maxEntities) {
            components.resize(maxEntities);
        }
    };

}
