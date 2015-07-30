#include "memory"

#include "game.h"
#include "game_state_menu.h"
#include "game_state_world.h"

int main() {
	std::shared_ptr<Game> game{new Game};
	std::shared_ptr<GameStateWorld> menu{new GameStateWorld{game}};
	game->pushState(menu);
	game->gameLoop();
    return 0;
};


