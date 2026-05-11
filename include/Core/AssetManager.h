#pragma once
#include <unordered_map>
#include <iostream>

#include "SFML/Graphics.hpp"

namespace MyGame::Core {

    class AssetManager {
        std::unordered_map<std::string, sf::Texture> textures;
        sf::Texture defaultTexture;
    public:
        AssetManager();
        sf::Texture& addTexture(std::string_view key, std::string_view filepath);
        sf::Texture& getTexture(std::string_view key);
    };

}
