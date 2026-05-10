#include "../../include/ECS/Registry.h"

namespace MyGame::ECS {

    Registry::Registry() {
        entities.resize(MAX_ENTITIES);
        positions.resize(MAX_ENTITIES);
        velocities.resize(MAX_ENTITIES);
        sprites.resize(MAX_ENTITIES);
    }

    Entity Registry::createEntity() {
        Entity id = entityCount;
        entityCount++;
        return id;
    }

    void Registry::addPosition(Entity entity, Components::Position position) {
        positions[entity] = position;
        entities[entity].set(Components::typeToId(Components::Type::POSITION));
    }

    void Registry::addVelocity(Entity entity, Components::Velocity velocity) {
        velocities[entity] = velocity;
        entities[entity].set(Components::typeToId(Components::Type::VELOCITY));
    }

    void Registry::addSprite(Entity entity, Components::Sprite sprite) {
        sprites[entity] = sprite;
        entities[entity].set(Components::typeToId(Components::Type::SPRITE));
    }

    Components::Position& Registry::getPosition(Entity entity) {
        return positions[entity];
    }

    Components::Velocity& Registry::getVelocity(Entity entity) {
        return velocities[entity];
    }

    Components::Sprite & Registry::getSprite(Entity entity) {
        return sprites[entity];
    }

    bool Registry::hasComponents(Entity entity, std::bitset<Components::MAX_COMPONENTS> mask) const {
        return (entities[entity] & mask) == mask;
    }

    const std::size_t Registry::getEntityCount() const {
        return entityCount;
    }
}
