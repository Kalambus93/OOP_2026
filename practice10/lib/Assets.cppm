module;

#include <SFML/Graphics.hpp>

export module Assets;

import std;

export void LoadingTexture(sf::Texture& texture, std::string path) {
    if (!texture.loadFromFile(path)) {
        std::println("Failed to load {}", path);
    }

    std::println("Added Texture {}", path);
}

export sf::Sprite CreateSprite(sf::Texture& texture, sf::Vector2i position, sf::Vector2i size) {
    sf::Sprite sprite(texture);
    sprite.setTextureRect(sf::IntRect(position, size));
    return sprite;
}