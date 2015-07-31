#include <memory>

#include "game_manager.h"
#include "game_state_menu.h"


void GameManager::start() {
    auto game = std::make_shared<Game>();
    createMenuState();
    game->loop();
}

void GameManager::createMenuState() {
    auto menuState = std::make_shared<GameStateMenu>(this->game);
    std::vector<std::unique_ptr<input::MenuInput>> inputs {
        std::unique_ptr<input::MenuInput>(new input::MenuInput{menuState})
    };
    menuState->setInputs(inputs);
    this->game->pushState(menuState);
}
  
