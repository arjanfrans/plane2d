#include <memory>

#include <SFML/Graphics.hpp>

#include "menu_input.h"

#include "../../utils/logger.h"
#include "menu_state.h"

namespace pl {

class MenuState;

MenuInput::MenuInput(std::shared_ptr<MenuState> state) : Input(state->engine), state{state} {
}

bool MenuInput::update(sf::Event event) {
    // Out of the switch to allow movement interactions simulationously with other input.
    if (event.type == sf::Event::MouseMoved) {
        mouseMovement(event);
    }

    switch (event.type) {
        case sf::Event::KeyPressed:
            return keyInput(event);
        case sf::Event::MouseButtonPressed:
            return mouseClick(event);
        default:
            return false;
    }
}

bool MenuInput::mouseClick(sf::Event event) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        auto buttons = this->state->getButtons();
        auto position = this->state->engine->window.mapPixelToCoords(
            sf::Mouse::getPosition(this->state->engine->window));
        bool overlaps = false;
        for (auto &button : buttons) {
            sf::Vector2f floatPosition{static_cast<float>(position.x), static_cast<float>(position.y)};
            if (button->overlaps(floatPosition)) {
                this->state->select();
                // This means that only ONE button can be overlapt at once.
                return true;
            }
        }
    }
    return false;
}

bool MenuInput::mouseMovement(sf::Event event) {
    auto buttons = this->state->getButtons();
    auto position = this->state->engine->window.mapPixelToCoords(
        sf::Mouse::getPosition(this->state->engine->window));
    for (auto &button : buttons) {
        sf::Vector2f floatPosition{static_cast<float>(position.x), static_cast<float>(position.y)};
        if (button->overlaps(floatPosition)) {
            this->state->setSelectedItem(button->name);
            // This means that only ONE button can be overlapt at once.
            return true;
        }
    }
    return false;
}

bool MenuInput::keyInput(sf::Event event) {
    switch (event.key.code) {
        case sf::Keyboard::Up:
            this->state->moveUp();
            return true;
        case sf::Keyboard::Down:
            this->state->moveDown();
            return true;
        case sf::Keyboard::Return:
            this->state->select();
            return true;
        default:
            return false;
    }
}
}
