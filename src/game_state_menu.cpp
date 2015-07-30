#include "game.h"
#include "game_state_menu.h"

GameStateMenu::GameStateMenu(std::shared_ptr<Game> game) {
    this->game = game;
}

void GameStateMenu::update(const float dt) {
}
