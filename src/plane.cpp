#include <memory>

#include "engine/game.h"
#include "engine/states/menu/menu_state.h"
#include "engine/states/state.h"
#include "engine/states/menu/menu_input.h"
#include "engine/states/menu/menu_view.h"
#include "plane.h"

void Plane::createStates() {
    createMenuState();
}

void Plane::createMenuState() {
    auto menuState = std::make_shared<pl::MenuState>(this->stateManager);
    std::vector<pl::MenuInput> inputs{pl::MenuInput{menuState}};
    std::vector<pl::MenuView> views{pl::MenuView{menuState}};
    menuState->setInputs(inputs);
    menuState->setViews(views);
    this->stateManager->pushState(menuState);
    return;
}

