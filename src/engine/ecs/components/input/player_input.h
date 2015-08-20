#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "../input_component.h"
#include "../../player.h"

namespace pl {

class PlayerInput : public InputComponent {

public:
    PlayerInput(std::shared_ptr<Player> player);
    bool checkInput(sf::Event event);

private:
    std::shared_ptr<Player> player;
};
}
