#pragma once

#include <SFML/Graphics.hpp>

namespace pl {

class InputComponent {

public:
    virtual bool checkInput(sf::Event input) = 0;
};
}
