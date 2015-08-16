#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../player.h"

namespace pl {

class ViewComponent {

public:
    void setTexture(sf::Texture &texture);

private:
    sf::Sprite sprite;
};
}
