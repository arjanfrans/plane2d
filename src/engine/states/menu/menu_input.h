#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "../../input/input.h"

namespace pl {

class MenuState;

class MenuInput : public Input {

public:
    MenuInput(std::shared_ptr<MenuState> state);
    bool update(sf::Event event);

private:
    std::shared_ptr<MenuState> state;
    bool keyInput(sf::Event);
    bool mouseClick(sf::Event);
    bool mouseMovement(sf::Event);
};
}
