#include "game.h"
#include "states/state_builder.h"
#include "ecs/entity_builder.h"
#include "input/global_input.h"
#include "utils/logger.h"

INITIALIZE_LOGGER

namespace pl {
Game::Game() : engine{nullptr} {
    auto config = std::make_shared<pl::Config>();
    config->load();
    this->config = config;

    this->engine = std::make_shared<Engine>(this->config);
    auto stateBuilder = std::unique_ptr<StateBuilder>{new StateBuilder{this->engine}};

    this->engine->setStateBuilder(std::move(stateBuilder));
    // EntityBuilder entityBuilder{this->engine};
    // this->engine->setEntityBuilder(std::move(entityBuilder));

    this->engine->setGlobalInput(std::unique_ptr<GlobalInput>{new GlobalInput{this->engine}});
    LOG(INFO) << "Working";
}
void Game::start() {
    createStates();
    this->engine->loop();
    return;
}
}
