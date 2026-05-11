#include "../../include/ECS/Registry.h"

namespace MyGame::ECS {

    Registry::Registry() {
        entities.resize(MAX_ENTITIES);
    }

    Entity Registry::createEntity() {
        return entityCount++;
    }

    bool Registry::hasComponents(Entity entity, std::bitset<Components::MAX_COMPONENTS> mask) const {
        return (entities[entity] & mask) == mask;
    }

    const std::size_t Registry::getEntityCount() const {
        return entityCount;
    }
}
