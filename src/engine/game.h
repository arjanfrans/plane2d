#ifndef GAME_H
#define GAME_H

#include "states/state_manager.h"

namespace pl {
class Game {

public:
    Game();
    void start();
    std::shared_ptr<StateManager> stateManager;

private:
    virtual void createStates() = 0;
};
}
#endif
