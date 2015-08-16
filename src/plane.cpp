#include "engine/states/state_builder.h"
#include "plane.h"

void Plane::createStates() {
    auto stateBuilder = this->engine->getStateBuilder();
    auto menuState = stateBuilder.menuState();
    this->engine->pushState(menuState);
}

void Plane::createGameState() {
    auto stateBuilder = this->engine->getStateBuilder();
    auto gameState = stateBuilder.worldState();

    // auto player = 

    // gameState->addEntity();
    this->engine->pushState(gameState);

}

