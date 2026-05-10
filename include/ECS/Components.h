#pragma once
#include <cstdint>

#include "SFML/Graphics/RectangleShape.hpp"

namespace MyGame::ECS::Components {
    constexpr int MAX_COMPONENTS = 128;

    enum class Type : std::size_t {
        POSITION    = 0,
        VELOCITY    = 1,
        SPRITE      = 2
    };

    inline std::size_t typeToId(Type type) {
        return static_cast<std::size_t>(type);
    }

    struct Position {
        float x = 0.f;
        float y = 0.f;
    };

    struct Velocity {
        float vx = 0.f;
        float vy = 0.f;
    };

    struct Sprite {
        sf::RectangleShape sprite;
    };

}
