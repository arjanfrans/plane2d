#include "engine/states/state_builder.h"
#include "plane.h"

void Plane::createStates() {
    createGameState();
    auto stateBuilder = this->engine->getStateBuilder();
    auto menuState = stateBuilder.menuState();
    this->engine->addState("menu", menuState);
    this->engine->changeState("menu");
}

void Plane::createGameState() {
    auto stateBuilder = this->engine->getStateBuilder();
    auto gameState = stateBuilder.worldState();

    // auto player = 

    // gameState->addEntity();
    this->engine->addState("world", gameState);

}

