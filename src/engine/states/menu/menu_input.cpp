#include <memory>

#include <SFML/Graphics.hpp>

#include "menu_input.h"
#include "menu_state.h"

#include "../../utils/logger.h"

namespace pl {

MenuInput::MenuInput(std::shared_ptr<MenuState> state) {
    this->state = state;
}

void MenuInput::mouseClick(sf::Event event) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        auto buttons = this->state->getButtons();
        auto position = sf::Mouse::getPosition(this->state->stateManager->window);
        for (auto &button : buttons) {
            sf::Vector2f floatPosition{static_cast<float>(position.x), static_cast<float>(position.y)};
            if (button->overlaps(floatPosition)) {
                this->state->select();
                return;
            }
        }
    }
    return;
}

void MenuInput::mouseMovement(sf::Event event) {
    auto buttons = this->state->getButtons();
    auto position = sf::Mouse::getPosition(this->state->stateManager->window);
    for (auto &button : buttons) {
        sf::Vector2f floatPosition{static_cast<float>(position.x), static_cast<float>(position.y)};
        if (button->overlaps(floatPosition)) {
            this->state->setSelectedItem(button->name);
        }
    }
    return;
}

void MenuInput::keyInput(sf::Event event) {
    switch (event.key.code) {
        case sf::Keyboard::Up:
            this->state->moveUp();
            break;
        case sf::Keyboard::Down:
            this->state->moveDown();
            break;
        case sf::Keyboard::Return:
            this->state->select();
            break;
        default:
            break;
    }
    return;
}

void MenuInput::closeWindow(sf::Event event) {
    this->state->stateManager->window.close();
    LOG(INFO) << "Closing window.";
    return;
}
}
