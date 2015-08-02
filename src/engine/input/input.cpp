#include <memory>

#include <SFML/Graphics.hpp>

#include "input.h"

namespace pl {

void Input::update(sf::Event event) {
    // Out of the switch to allow movement interactions simulationously with other input.
    if (event.type == sf::Event::MouseMoved) {
        mouseMovement(event);
    }

    switch (event.type) {
        case sf::Event::Closed:
            closeWindow(event);
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
}
