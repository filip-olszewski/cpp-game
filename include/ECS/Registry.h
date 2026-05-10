#pragma once
#include <bitset>
#include <cstddef>
#include <vector>

#include "Components.h"

namespace MyGame::ECS {

    using Entity = std::size_t;
    constexpr std::size_t MAX_ENTITIES = 2048;

    class Registry {
        std::size_t entityCount = 0;
        std::vector<std::bitset<Components::MAX_COMPONENTS>> entities;

        std::vector<Components::Position> positions;
        std::vector<Components::Velocity> velocities;
        std::vector<Components::Sprite> sprites;
    public:
        Registry();
        Entity createEntity();

        void addPosition(Entity entity, Components::Position position);
        void addVelocity(Entity entity, Components::Velocity velocity);
        void addSprite(Entity entity, Components::Sprite sprite);

        Components::Position& getPosition(Entity entity);
        Components::Velocity& getVelocity(Entity entity);
        Components::Sprite& getSprite(Entity entity);

        bool hasComponents(Entity entity, std::bitset<Components::MAX_COMPONENTS> mask) const;
        const std::size_t getEntityCount() const;
    };

}
