#include <memory>

#include "../engine.h"
#include "state.h"
namespace pl {
State::State(std::shared_ptr<Engine> engine)
    : engine{engine}, config{engine->config} {
}
}
