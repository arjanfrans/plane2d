#include "entity_container.h"
#include "../engine/ecs/player.h"

namespace platformer {

void EntityContainer::update(float dt) {
}

void EntityContainer::draw(sf::RenderWindow &window) {
    this->player->updateView(window);
}

void EntityContainer::updateControllables(sf::Event event) {
    this->player->updateInput(event);
}
}
