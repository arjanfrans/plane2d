#pragma once

#include <SFML/Graphics.hpp>

namespace pl {

class EntityContainer {

public:
    EntityContainer();
    virtual void updateControllables(sf::Event event) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
};
}
