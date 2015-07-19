#include "memory"

#include "game.h"
#include "game_state_menu.h"

int main() {
	Game game;
	std::unique_ptr<GameStateMenu> menu{new GameStateMenu(std::make_unique<GameStateMenu>{game}};
	game.pushState(menu);
	game.gameLoop();
    return 0;
}


