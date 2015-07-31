#include <iostream>

#include "game_state.h"
#include "game_state_menu.h"
#include "game_manager.h"

int main() {
    GameManager manager;
    manager.start();
    auto game = std::make_shared<Game>();
    auto menuState = std::make_shared<GameStateMenu>(game);
    game->pushState(menuState);
    game->loop();
    return 0;
}
