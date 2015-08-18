#include "platformer.h"
#include "entity_container.h"

namespace platformer {

void Platformer::createStates() {
    createGameState();
    this->engine->addState("menu", this->stateBuilder->menuState());
    this->engine->changeState("menu");
}

void Platformer::createGameState() {
    auto gameState = this->stateBuilder->worldState();

    auto player = this->entityBuilder->player();
    gameState->setEntityContainer(std::unique_ptr<EntityContainer>{new EntityContainer()});

    this->engine->addState("world", gameState);
}
}
