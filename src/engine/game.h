#pragma once

#include <memory>

#include "config.h"
#include "engine.h"

namespace pl {
class Game {

public:
    Game();
    std::shared_ptr<Config> config;
    void start();
    std::shared_ptr<Engine> engine;

private:
    virtual void createStates() = 0;
};
}
