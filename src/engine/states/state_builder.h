#ifndef STATE_BUILDER_H
#define STATE_BUILDER_H
#include <memory>

#include "menu/menu_state.h"
#include "world/world_state.h"
#include "../engine.h"

namespace pl {

class Engine;

class StateBuilder {

public:
    static std::shared_ptr<MenuState> menuState(std::shared_ptr<Engine> engine);
    static std::shared_ptr<WorldState> worldState(std::shared_ptr<Engine> engine);
};
}
#endif
