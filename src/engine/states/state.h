#ifndef STATES_STATE_H
#define STATES_STATE_H

#include <memory>
#include <vector>

#include "state_manager.h"

namespace pl {

class StateManager;

class State {

public:
    std::shared_ptr<StateManager> stateManager;
    virtual void update(const float dt) = 0;
};
}

#endif
