#include <iostream>

#ifndef DEBUG
#define DEBUG
#endif

#ifdef DEBUG
#define D(x) std::cout << x;
#else
#define D(x)
#endif

#include "game.h"
#include "game_state.h"
#include "game_state_menu.h"

int main() {
    D("Program start");
    auto game = std::make_shared<Game>();
    auto menuState = std::make_shared<GameStateMenu>(game);
    game->pushState(menuState);
    game->init(); 
    game->loop();
    return 0;
}
