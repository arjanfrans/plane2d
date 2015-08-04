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

private:
    std::shared_ptr<MenuState> state;
    void keyInput(sf::Event);
    void mouseClick(sf::Event);
    void mouseMovement(sf::Event);
};
}

#endif
