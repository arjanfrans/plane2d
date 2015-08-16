#pragma once

#include <memory>

#include "config.h"
#include "engine.h"
#include "states/state_builder.h"
#include "ecs/entity_builder.h"

namespace pl {

class Game {

public:
    Game();
    std::shared_ptr<Config> config;
    void start();
    std::shared_ptr<Engine> engine;
    std::shared_ptr<StateBuilder> stateBuilder;
    std::shared_ptr<EntityBuilder> entityBuilder;

private:
    virtual void createStates() = 0;
};
}
