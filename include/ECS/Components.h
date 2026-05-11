#pragma once
#include <cstdint>

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"

namespace MyGame::ECS::Components {

    class ComponentManager {
        static inline uint32_t componentCounter = 0;
    public:
        template <typename T>
        static uint32_t getId() {
            static uint32_t id = componentCounter++;
            return id;
        }
    };

    constexpr uint32_t MAX_COMPONENTS = 256;

    struct Position {
        float x = 0.f;
        float y = 0.f;
    };

    struct Velocity {
        float vx = 0.f;
        float vy = 0.f;
        float speed = 200.f;
    };

    struct Render {
        const sf::Texture* texture = nullptr;
        sf::IntRect rect;

        Render() = default;
        explicit Render(const sf::Texture& texture) : texture(&texture) {}
        Render(const sf::Texture& texture, const sf::IntRect& rect) : texture(&texture), rect(rect) {}
    };

    struct Animation {
        uint8_t currentFrame = 0;
        uint8_t frameCount = 0;
        uint8_t frameGap = 0;
        float animationSpeed = 0.1f;
        float accumulator = 0;

        Animation() = default;
        Animation(uint8_t frameCount, uint8_t frameGap, float animationSpeed = 0.1f)
            : frameCount(frameCount), frameGap(frameGap), animationSpeed(animationSpeed) {}
    };

    struct Input {
        enum class Key : uint8_t {
            NONE    = 0,
            UP      = 1,
            DOWN    = 2,
            LEFT    = 4,
            RIGHT   = 8
        };

        static uint8_t keyToValue(Key key) {
            return static_cast<uint8_t>(key);
        }

        std::bitset<UINT8_MAX> pressed;

        bool keyUp = false;
        bool keyDown = false;
        bool keyRight = false;
        bool keyLeft = false;
    };

}
