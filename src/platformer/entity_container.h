#pragma once

#include <memory>

#include "../engine/ecs/entity_container.h"
#include "../engine/ecs/player.h"

namespace platformer {
class EntityContainer : public pl::EntityContainer {

public:
    void updateControllables(sf::Event event);
    void update(float dt);
    void draw(sf::RenderWindow &window);
    std::shared_ptr<pl::Player> player;
};
}
