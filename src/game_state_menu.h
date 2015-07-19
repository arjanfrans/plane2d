#ifndef GAME_STATE_MENU_H
#define GAME_STATE_MENU_H

#include "memory"

#include "SFML/Graphics.hpp"

#include "game_state.h"

class GameStateMenu : public GameState {
	
	private:
		sf::View view;

	public:
		GameStateMenu(std::unique_ptr<Game> game);

		virtual void draw(const float dt);
		virtual void update(const float dt);
		virtual void handleInput();

};

#endif
