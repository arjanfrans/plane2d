#ifndef GAME_H
#define GAME_H

#include <memory>

#include "config.h"
#include "states/state_manager.h"

namespace pl {
class Game {

public:
    Game();
    std::shared_ptr<Config> config;
    void start();
    std::shared_ptr<StateManager> stateManager;

private:
    virtual void createStates() = 0;
};
}
#endif
