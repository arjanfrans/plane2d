#include <memory>
#include <map>

#include "state_builder.h"
#include "menu/menu_input.h"
#include "menu/menu_view.h"
#include "world/world_input.h"
#include "world/world_view.h"
#include "../engine.h"

#include "../tile_map.h"

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

std::shared_ptr<WorldState> StateBuilder::worldState(std::shared_ptr<EntityContainer> entityContainer) {
    auto worldState = std::make_shared<WorldState>(this->engine, entityContainer);

    std::vector<WorldInput> inputs{WorldInput{worldState}};

    auto config = this->engine->config->get("game");

    std::map<std::string, WorldView> views{
        {"world", WorldView{worldState, config["virtualWidth"].as<float>(),
                            config["virtualHeight"].as<float>()}}};

    worldState->setInputs(inputs);
    worldState->setViews(views);
    

    auto& tmxMap = this->engine->resources.map("platformer.tmx");

    TileMap map;
    map.parseTmx(tmxMap);


    return worldState;
}
}
