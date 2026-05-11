#include "../../include/Core/AssetManager.h"


namespace MyGame::Core {

    AssetManager::AssetManager() {
        sf::Image image;
        image.createMaskFromColor(sf::Color::Magenta);
        defaultTexture.loadFromImage(image);
    }

    sf::Texture& AssetManager::addTexture(std::string_view key, std::string_view filepath) {
        std::string stringKey = std::string(key);

        if (textures.contains(key.data())) {
            return textures[key.data()];
        }

        sf::Texture tex;
        if (!tex.loadFromFile(filepath)) {
            std::cerr << "[WARN] Could not load texture for key '"
                      << key << "' and filepath '" << filepath << "'.\n";
            return defaultTexture;
        }

        textures.try_emplace(key.data(), std::move(tex));
        return textures[key.data()];
    }

    sf::Texture& AssetManager::getTexture(std::string_view key) {
        if (textures.contains(key.data())) {
            return textures[key.data()];
        }
        return defaultTexture;
    }
}
