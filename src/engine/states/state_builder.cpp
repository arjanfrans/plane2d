#include <memory>

#include "state_builder.h"
#include "../engine.h"
#include "menu/menu_input.h"
#include "menu/menu_view.h"
#include "menu/menu_state.h"
#include "world/world_input.h"
#include "world/world_view.h"
#include "world/world_state.h"

namespace pl {

StateBuilder::StateBuilder(std::shared_ptr<Engine> engine) : engine{engine} {
}

std::shared_ptr<MenuState> StateBuilder::menuState() {
    auto menuState = std::make_shared<MenuState>(this->engine);
    std::vector<MenuInput> inputs{MenuInput{menuState}};
    auto config = this->engine->config->get("menu");
    std::vector<MenuView> views{
        MenuView{menuState, config["virtualWidth"].as<float>(), config["virtualHeight"].as<float>()}};
    menuState->setInputs(inputs);
    menuState->setViews(views);
    return menuState;
}

std::shared_ptr<WorldState> StateBuilder::worldState() {
    auto worldState = std::make_shared<WorldState>(this->engine);
    std::vector<WorldInput> inputs{WorldInput{worldState}};
    auto config = this->engine->config->get("game");
    std::vector<WorldView> views{
        WorldView{worldState, config["virtualWidth"].as<float>(), config["virtualHeight"].as<float>()}};
    worldState->setInputs(inputs);
    worldState->setViews(views);
    return worldState;
}
}

