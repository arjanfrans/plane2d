#include "memory"

#include "game.h"
#include "game_state_menu.h"

int main() {
	std::shared_ptr<Game> game{new Game};
	std::shared_ptr<GameStateMenu> menu{new GameStateMenu{game}};
	game->pushState(menu);
	game->gameLoop();
    return 0;
};


