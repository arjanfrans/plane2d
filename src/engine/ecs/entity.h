#pragma once

#include <SFML/Graphics.hpp>

namespace pl {

class Entity {

public:
    Entity();
    void setSize(float width, float height);
    const sf::Vector2f &getSize();
    void setPosition(float x, float y);
    const sf::Vector2f &getPosition();
    void setOrigin(float x, float y);
    const sf::Vector2f &getOrigin();

private:
    sf::Vector2f size;
    sf::Vector2f position;
    sf::Vector2f origin;
};
}
