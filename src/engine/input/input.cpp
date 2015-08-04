#include <memory>

#include <SFML/Graphics.hpp>

#include "input.h"
#include "../utils/logger.h"

namespace pl {

Input::Input(std::shared_ptr<Engine> engine) : engine{engine} {
}

void Input::update(sf::Event event) {
    // Out of the switch to allow movement interactions simulationously with other input.
    if (event.type == sf::Event::MouseMoved) {
        mouseMovement(event);
    }

    switch (event.type) {
        case sf::Event::Closed:
            closeWindow(event);
            break;
        case sf::Event::Resized:
            onResize(event);
            break;
        case sf::Event::KeyPressed:
            keyInput(event);
            break;
        case sf::Event::MouseButtonPressed:
            mouseClick(event);
            break;
        default:
            break;
    }
    return;
}

void Input::closeWindow(sf::Event event) {
    this->engine->window.close();
    LOG(INFO) << "Closing window.";
    return;
}
}
