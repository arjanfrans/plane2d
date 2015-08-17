#pragma once

#include <SFML/Graphics.hpp>
#include "dynamic_entity.h"

namespace pl {
class MovableEntity : public DynamicEntity {

public:
    void move(float dt);
    void setVelocity(float x, float y);
    void update(float dt);
    const sf::Vector2f &getVelocity();

private:
    sf::Vector2f velocity;
};
}
