#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../view_component.h"
#include "../../player.h"

namespace pl {

class PlayerView : public ViewComponent {
public:
    PlayerView(std::shared_ptr<Player> player);

private:
    std::shared_ptr<Player>  player;
};
}
