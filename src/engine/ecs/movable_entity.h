#pragma once

#include <SFML/Graphics.hpp>
#include "entity.h"

namespace pl {
class MovableEntity : public virtual Entity {

public:
    void move(float dt);
    void setVelocity(float x, float y);
    void update(float dt);
    const sf::Vector2f &getVelocity();

private:
    sf::Vector2f velocity;
};
}
