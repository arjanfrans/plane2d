#include "platformer.h"
#include "entity_container.h"
#include "../engine/utils/logger.h"
#include "../engine/states/world/world_view.h"

namespace platformer {

void Platformer::createStates() {
    createGameState();
    this->engine->addState("menu", this->stateBuilder->menuState());
    this->engine->changeState("menu");
}

void Platformer::createGameState() {
    auto player = this->entityBuilder->player();
    auto entityContainer = std::make_shared<EntityContainer>();

    entityContainer->player = player;
    auto gameState = this->stateBuilder->worldState(entityContainer);
    gameState->getView("world").setCameraFollow(player);
    this->engine->addState("world", gameState);
}
}
