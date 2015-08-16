#include "state.h"
#include "../utils/logger.h"

namespace pl {
State::State(std::shared_ptr<Engine> engine) : engine{engine}, config{engine->config} {
}

void State::onExit() {
    this->engine->window.close();
    LOG(INFO) << "Closing window.";
    return;
}
}

