#pragma once

#include <memory>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include <tmxparser/Tmx.h>

namespace pl {
class ResourceManager {

public:
    sf::Font &font(std::string name);
    sf::Texture &texture(std::string name);
    Tmx::Map &map(std::string name);

private:
    std::map<std::string, std::unique_ptr<sf::Font>> fonts;
    std::map<std::string, std::unique_ptr<sf::Texture>> textures;
    std::map<std::string, std::unique_ptr<Tmx::Map>> maps;
};
}
