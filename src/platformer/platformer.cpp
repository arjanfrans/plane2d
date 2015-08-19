#include "platformer.h"
#include "entity_container.h"
#include "../engine/utils/logger.h"

namespace platformer {

void Platformer::createStates() {
    createGameState();
    this->engine->addState("menu", this->stateBuilder->menuState());
    this->engine->changeState("menu");
}

void Platformer::createGameState() {

    auto player = this->entityBuilder->player();
    auto entityContainer = std::make_shared<EntityContainer>();
    entityContainer->player = std::move(player);
    auto gameState = this->stateBuilder->worldState(entityContainer);

    this->engine->addState("world", gameState);
}
}
