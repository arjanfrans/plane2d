#pragma once

#include <SFML/Graphics.hpp>

namespace pl {

class Drawable {

public:
    sf::Sprite sprite;
    virtual void draw();
};
}
