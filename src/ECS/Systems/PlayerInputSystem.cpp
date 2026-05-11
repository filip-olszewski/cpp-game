#include "../../../include/ECS/Systems/PlayerInputSystem.h"

#include "SFML/Window/Keyboard.hpp"

namespace MyGame::ECS::Systems {

    PlayerInputSystem::PlayerInputSystem() {
        requiredMask.set(Components::ComponentManager::getId<Components::Input>());
    }

    void PlayerInputSystem::update(Registry &registry, float dt) {
        for (Entity e = 0; e < registry.getEntityCount(); ++e) {
            if (!registry.hasComponents(e, requiredMask)) {
                continue;
            }

            auto& inputComponent = registry.getComponent<Components::Input>(e);

            using namespace sf::Keyboard;
            inputComponent.keyUp = isKeyPressed(Key::W);
            inputComponent.keyDown = isKeyPressed(Key::S);
            inputComponent.keyRight = isKeyPressed(Key::D);
            inputComponent.keyLeft = isKeyPressed(Key::A);
        }
    }

}
