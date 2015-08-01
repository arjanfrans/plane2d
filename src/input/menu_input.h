#ifndef INPUT_MENU_INPUT_H
#define INPUT_MENU_INPUT_H

#include <memory>

#include <SFML/Graphics.hpp>

class GameStateMenu;
#include "../game_state_menu.h"

namespace input {

class MenuInput {

public:
    MenuInput(std::shared_ptr<GameStateMenu> state);
    std::shared_ptr<GameStateMenu> state = nullptr;
    void update(sf::Event event);

private:
    void keyInput(sf::Event);
    void mouseInput(sf::Event);
    void closeWindow(sf::Event event);
};
}

#endif
