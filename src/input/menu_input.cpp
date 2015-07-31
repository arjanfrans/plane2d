#include <memory>

#include <SFML/Graphics.hpp>

#include "menu_input.h"
#include "../game_state_menu.h"

namespace input {

MenuInput::MenuInput(std::shared_ptr<GameStateMenu> state) {
    this->state = state;
}

void MenuInput::update(sf::Event event) {
    switch(event.type) {
        case sf::Event::Closed: 
            closeWindow(event);
            break;
        default:
            break;
    }
    return;
}

void MenuInput::closeWindow(sf::Event event) {
    this->state->game->window->close();
    return;
}


}
