#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "../input_component.h"
#include "../../player.h"

namespace pl {

class PlayerInput : public InputComponent {

public:
    PlayerInput(Player &player);
    bool checkInput(sf::Event event);

private:
    Player &player;
};
}
