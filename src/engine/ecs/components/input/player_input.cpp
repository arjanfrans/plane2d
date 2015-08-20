#include "player_input.h"
#include "../../../utils/logger.h"

namespace pl {

PlayerInput::PlayerInput(std::shared_ptr<Player> player) : player{player} {
}

bool PlayerInput::checkInput(sf::Event event) {
    if (event.type != sf::Event::KeyPressed) {
        return false;
    }

    switch (event.key.code) {
        case sf::Keyboard::Up:
            LOG(INFO) << "Player moving up.";
            return true;
        default:
            return false;
    }
}
}
