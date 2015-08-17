#include "world_input.h"
#include "../../utils/logger.h"

namespace pl {

WorldInput::WorldInput(std::shared_ptr<WorldState> state) : Input(state->engine) {
}

bool WorldInput::update(sf::Event event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
            return keyInput(event);
        default:
            return false;
    }
}

bool WorldInput::keyInput(sf::Event event) {
    switch(event.key.code) {
        case sf::Keyboard::Escape:
            this->engine->changeState("menu");
            return true;
        default:
            return false;
    }
}

}
