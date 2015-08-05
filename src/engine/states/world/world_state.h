#ifndef WORLD_STATE_H
#define WORLD_STATE_H

#include <memory>
#include <vector>

#include "../state.h"
#include "../../input/input.h"
#include "../../engine.h"
#include "world_view.h"

namespace pl {

class WorldView;

class WorldState : public State {

public:
    WorldState(std::shared_ptr<Engine> engine);
    // void setInputs(std::vector<Input> inputs);
    void setViews(std::vector<WorldView> view);
    void update(const float dt);

private:
    // std::vector<MenuInput> inputs;
    std::vector<WorldView> views;
    // void updateInputs();
    void updateViews();
};
}

#endif
