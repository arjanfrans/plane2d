#include "plane.h"

void Plane::createStates() {
    createGameState();
    this->engine->addState("menu", this->stateBuilder->menuState());
    this->engine->changeState("menu");
}

void Plane::createGameState() {
    auto gameState = this->stateBuilder->worldState();

    auto player = this->entityBuilder->player();

    this->engine->addState("world", gameState);
}
