#ifndef WORLD_STATE_H
#define WORLD_STATE_H

#include <memory>
#include <vector>

#include "../state.h"

namespace pl {

class WorldState : public State {

public:
    WorldState(std::shared_ptr<StateManager> stateManager);
    // void setInputs(std::vector<Input> inputs);
    // void setViews(std::vector<Input> view);
    void update(const float dt);

private:
    // std::vector<MenuInput> inputs;
    // std::vector<MenuView> views;
    void updateInputs();
    void updateViews();
};
}

#endif
