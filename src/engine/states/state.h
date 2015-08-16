#pragma once

#include <memory>

#include "../engine.h"
#include "../config.h"

namespace pl {

class State {

public:
    State(std::shared_ptr<Engine> engine);
    std::shared_ptr<Engine> engine;
    virtual void update(const float dt) = 0;
    virtual void updateInput(sf::Event event) = 0;
    virtual void resizeWindow(float x, float y) = 0;
    std::shared_ptr<Config> config;
    void onExit();

private:
};
}

