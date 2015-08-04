#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <memory>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>

namespace pl {
class ResourceManager {

public:
    sf::Font &font(std::string name);
    sf::Texture &texture(std::string name);

private:
    std::map<std::string, std::unique_ptr<sf::Font>> fonts;
    std::map<std::string, std::unique_ptr<sf::Texture>> textures;
};
}
#endif
