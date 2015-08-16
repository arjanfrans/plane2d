#pragma once

#include <SFML/Graphics.hpp>

namespace pl {

class InputComponent {

public:
    bool checkInput(sf::Event input);
};
}
