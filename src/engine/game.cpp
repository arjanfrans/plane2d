#include "game.h"

#include "input/global_input.h"
#include "utils/logger.h"

INITIALIZE_LOGGER

namespace pl {

Game::Game() : engine{nullptr} {
    auto config = std::make_shared<pl::Config>();
    config->load();
    this->config = config;

    this->engine = std::make_shared<Engine>(this->config);

    this->engine->setGlobalInput(std::unique_ptr<GlobalInput>{new GlobalInput{this->engine}});

    this->stateBuilder = std::make_shared<StateBuilder>(this->engine);
    this->entityBuilder = std::make_shared<EntityBuilder>(this->engine);

    this->engine->entityBuilder = this->entityBuilder;
    this->engine->stateBuilder = this->stateBuilder;
    LOG(INFO) << "Working";
}
void Game::start() {

    createStates();
    this->engine->loop();
    return;
}
}
