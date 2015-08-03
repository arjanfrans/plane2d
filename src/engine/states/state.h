#ifndef STATES_STATE_H
#define STATES_STATE_H

#include <memory>
#include <vector>

#include "../engine.h"
#include "../config.h"

namespace pl {

class Engine;

class State {

public:
    State(std::shared_ptr<Engine> engine);
    std::shared_ptr<Engine> engine;
    virtual void update(const float dt) = 0;
    std::shared_ptr<Config> config;
};
}

#endif
