#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../view_component.h"
#include "../../player.h"

namespace pl {

class PlayerView : public ViewComponent {
public:
    PlayerView(Player &player);

private:
    Player &player;
};
}
