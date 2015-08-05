#pragma once

#include <SFML/Graphics.hpp>
namespace pl {

class View {

public:
    View(float virtualWidth, float virtualHeight);
    virtual void resize(float width, float height) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    sf::FloatRect virtualResolutionViewport(float x, float y);
    float virtualWidth;
    float virtualHeight;
};
}
