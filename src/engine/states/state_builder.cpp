#include <memory>

#include "state_builder.h"
#include "../engine.h"
#include "menu/menu_state.h"
#include "world/world_state.h"

namespace pl {

std::shared_ptr<MenuState> StateBuilder::menuState(std::shared_ptr<Engine> engine) {
    auto menuState = std::make_shared<MenuState>(engine);
    std::vector<MenuInput> inputs{MenuInput{menuState}};
    std::vector<MenuView> views{MenuView{menuState}};
    menuState->setInputs(inputs);
    menuState->setViews(views);
    return menuState;
}

std::shared_ptr<WorldState> StateBuilder::worldState(std::shared_ptr<Engine> engine) {
    auto worldState = std::make_shared<WorldState>(engine);
    std::vector<WorldView> views{WorldView{worldState}};
    worldState->setViews(views);
    return worldState;
}
}

