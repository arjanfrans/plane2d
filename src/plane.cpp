#include "plane.h"

void Plane::createStates() {
    createGameState();
    auto &stateBuilder = this->engine->getStateBuilder();
    this->engine->addState("menu", stateBuilder->menuState());
    this->engine->changeState("menu");
}

void Plane::createGameState() {
    auto &stateBuilder = this->engine->getStateBuilder();
    auto gameState = stateBuilder.worldState();

    auto &entityBuilder = this->engine->getEntityBuilder();
    auto player = entityBuilder.player();

    // gameState->addEntity();
    this->engine->addState("world", gameState);
}
