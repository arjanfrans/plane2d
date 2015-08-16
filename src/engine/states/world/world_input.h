#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "world_state.h"
#include "../../input/input.h"

namespace pl {

class WorldState;

class WorldInput : public Input {
public:
    WorldInput(std::shared_ptr<WorldState> state);
    bool update(sf::Event event);

private:
    std::shared_ptr<WorldState> state;
};
}
