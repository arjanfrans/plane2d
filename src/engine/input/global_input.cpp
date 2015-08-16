#include "global_input.h"
#include "../utils/logger.h"

namespace pl {

GlobalInput::GlobalInput(std::shared_ptr<Engine> engine) : Input{engine} {
}

bool GlobalInput::update(sf::Event event) {
    switch (event.type) {
        case sf::Event::Closed:
            closeWindow();
            return true;
        case sf::Event::Resized:
            onResize(event);
            return true;
        case sf::Event::KeyPressed:
            return keyInput(event.key.code);
        default:
            return false;
    }
}

void GlobalInput::onResize(sf::Event event) {
    this->engine->peekState()->resizeWindow(event.size.width, event.size.height);
    return;
}

void GlobalInput::closeWindow() {
    this->engine->window.close();
    LOG(INFO) << "Closing window.";
    return;
}
bool GlobalInput::keyInput(sf::Keyboard::Key code) {
    if (code == sf::Keyboard::Return && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) {
        this->engine->changeFullscreen();
        return true;
    } else if (code == sf::Keyboard::F4) {
        LOG(INFO) << "LAlt + F4 pressed.";
        closeWindow();
        return true;
    }
    return false;
}
}

