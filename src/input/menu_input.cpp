#include <memory>

#include <SFML/Graphics.hpp>

#include "menu_input.h"
#include "../game_state_menu.h"

#include "../utils/logger.h"

namespace input {

MenuInput::MenuInput(std::shared_ptr<GameStateMenu> state) {
    this->state = state;
}

void MenuInput::update(sf::Event event) {
    switch(event.type) {
        case sf::Event::Closed: 
            closeWindow(event);
            break;
        case sf::Event::KeyPressed:
            keyInput(event);
            break;
        default:
            break;
    }
    return;
}

void MenuInput::keyInput(sf::Event event) {
    switch(event.key.code) {
        case sf::Keyboard::Up:
            this->state->moveUp();
            break;
        case sf::Keyboard::Down:
            this->state->moveDown();
            break;
        default:
            break;
    }
    return;
}

void MenuInput::closeWindow(sf::Event event) {
    this->state->game->window.close();
    LOG(INFO) << "Closing window.";
    return;
}


}
