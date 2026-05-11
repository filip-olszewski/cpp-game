#pragma once
#include <bitset>
#include <cstddef>
#include <memory>
#include <unordered_map>
#include <vector>

#include "ComponentPool.h"
#include "Components.h"
#include "IPool.h"

namespace MyGame::ECS {

    using Entity = std::size_t;
    constexpr std::size_t MAX_ENTITIES = 2048;

    class Registry {
        std::size_t entityCount = 0;
        std::vector<std::bitset<Components::MAX_COMPONENTS>> entities;
        std::unordered_map<uint32_t, std::unique_ptr<IPool>> pools;

    public:
        Registry();
        Entity createEntity();

        template <typename T>
        void addComponent(Entity entity, T component) {
            uint32_t componentId = Components::ComponentManager::getId<T>();

            if (!pools.contains(componentId)) {
                pools[componentId] = std::make_unique<ComponentPool<T>>(MAX_ENTITIES);
            }

            auto pool = static_cast<ComponentPool<T>*>(pools[componentId].get());
            pool->components[entity] = component;
            entities[entity].set(componentId);
        }

        template <typename T>
        T& getComponent(Entity e) {
            uint32_t componentId = Components::ComponentManager::getId<T>();
            auto pool = static_cast<ComponentPool<T>*>(pools[componentId].get());
            return pool->components[e];
        }

        bool hasComponents(Entity entity, std::bitset<Components::MAX_COMPONENTS> mask) const;
        const std::size_t getEntityCount() const;
    };

}
