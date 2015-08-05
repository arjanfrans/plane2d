#include <memory>

#include "yaml-cpp/yaml.h"
#include "config.h"
#include "engine.h"
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
}
void Game::start() {
    createStates();
    this->engine->loop();
    return;
}
}
