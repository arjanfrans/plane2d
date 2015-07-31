#include <memory>

#include "game_manager.h"
#include "game_state_menu.h"

GameManager::GameManager() : game{nullptr} {
    this->game = std::make_shared<Game>();
}
void GameManager::start() {
    createMenuState();
    this->game->loop();
    return;
}

void GameManager::createMenuState() {
    auto menuState = std::make_shared<GameStateMenu>(this->game);
    std::vector<input::MenuInput> inputs {
        input::MenuInput{menuState}
    };
    menuState->setInputs(inputs);
    this->game->pushState(menuState);
    return;
}

