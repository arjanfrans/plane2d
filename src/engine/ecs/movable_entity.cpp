#include "movable_entity.h"
#include "../utils/logger.h"

namespace pl {

void MovableEntity::move(float dt) {
    auto position = getPosition() + this->velocity;
    setPosition(position.x, position.y);
}

void MovableEntity::setVelocity(float x, float y) {
    this->velocity.x = x;
    this->velocity.y = y;
}

const sf::Vector2f &MovableEntity::getVelocity() {
    return this->velocity;
}
}
