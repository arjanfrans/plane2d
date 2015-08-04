#include <memory>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>
#include "resource_manager.h"

#include "utils/logger.h"

namespace pl {
const std::string CONFIG_PATH = "data/";

sf::Font &ResourceManager::font(std::string name) {
    auto font = this->fonts.find(name);
    if (font != this->fonts.end()) {
        return *font->second.get();
    }
    auto newFont = std::unique_ptr<sf::Font>{new sf::Font()};
    if (!newFont->loadFromFile(CONFIG_PATH + "fonts/" + name)) {
        LOG(ERROR) << "Unable to load font: " + name;
    }
    this->fonts.emplace(name, std::move(newFont));
    return *this->fonts.at(name).get();
};

sf::Texture &ResourceManager::texture(std::string name) {
    auto texture = this->textures.find(name);
    if (texture != this->textures.end()) {
        return *texture->second.get();
    }
    auto newTexture = std::unique_ptr<sf::Texture>{new sf::Texture()};
    if (!newTexture->loadFromFile(CONFIG_PATH + "graphics/" + name)) {
        LOG(ERROR) << "Unable to load texture: " + name;
    }
    this->textures.emplace(name, std::move(newTexture));
    return *this->textures.at(name).get();
};
}
