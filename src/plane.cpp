#include "engine/states/state_builder.h"
#include "plane.h"

void Plane::createStates() {
    auto menuState = this->engine->stateBuilder.menuState(this->engine);
    this->engine->pushState(menuState);
}

void Plane::createGameState() {
    auto gameState = this->engine->stateBuilder.worldState(this->engine);

    // auto player = 

    // gameState->addEntity();
    this->engine->pushState(gameState);

}

