#pragma once

#include <SFML/Graphics.hpp>

namespace pl {

class Entity {

public:
    void setSize(float width, float height);
    const sf::Vector2f &getsize();
    void setPosition(float x, float y);
    const sf::Vector2f &getPosition();

private:
    sf::Vector2f size;
    sf::Vector2f position;
};
}
