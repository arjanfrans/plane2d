#pragma once

#include <SFML/Graphics.hpp>

namespace pl {

class Controllable {

public:
    bool updateInput(sf::Event event);
};
}
