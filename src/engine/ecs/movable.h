#pragma once

#include <SFML/Graphics.hpp>

namespace pl {
class Movable {

public:
    void move(float dt);
    void setVelocity(float x, float y);
    sf::Vector2f getVelocity();

private:
    sf::Vector2f velocity;
};
}
