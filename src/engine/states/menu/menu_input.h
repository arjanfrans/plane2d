#ifndef INPUT_MENU_INPUT_H
#define INPUT_MENU_INPUT_H

#include <memory>

#include <SFML/Graphics.hpp>

#include "menu_state.h"
#include "../../input/input.h"

namespace pl {

class MenuState;

class MenuInput : public Input {

public:
    MenuInput(std::shared_ptr<MenuState> state);
    void onResize(sf::Event event);
    bool update(sf::Event event);

private:
    std::shared_ptr<MenuState> state;
    bool keyInput(sf::Event);
    bool mouseClick(sf::Event);
    bool mouseMovement(sf::Event);
};
}

#endif
