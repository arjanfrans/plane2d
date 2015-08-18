#include "entity.h"

namespace pl {

Entity::Entity() {};


void Entity::setSize(float width, float height) {
    this->size.x = width;
    this->size.y = height;
}

const sf::Vector2f &Entity::getSize() {
    return this->size;
}

void Entity::setPosition(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}

const sf::Vector2f &Entity::getPosition() {
    return this->position;
}

void Entity::setOrigin(float x, float y) {
    this->origin.x = x;
    this->origin.y = y;
}

const sf::Vector2f &Entity::getOrigin() {
    return this->origin;
}

}
