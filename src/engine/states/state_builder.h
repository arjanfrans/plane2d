#pragma once

#include <memory>

#include "menu/menu_state.h"
#include "world/world_state.h"
#include "../engine.h"

namespace pl {

class Engine;

class StateBuilder {

public:
    std::shared_ptr<MenuState> menuState(std::shared_ptr<Engine> engine);
    std::shared_ptr<WorldState> worldState(std::shared_ptr<Engine> engine);
};
}
