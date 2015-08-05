#include "engine/states/state_builder.h"
#include "plane.h"

void Plane::createStates() {
    this->engine->pushState(pl::StateBuilder::menuState(this->engine));
}

