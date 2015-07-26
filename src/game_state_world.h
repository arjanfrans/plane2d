#ifndef GAME_STATE_WORLD_H
#define GAME_STATE_WORLD_H

#include "memory"

#include "game_state.h"

class GameStateWorld : public GameState {
	
	private:
		sf::View gameView;
		sf::View guiView;

	public:
		GameStateWorld(std::shared_ptr<Game> gane);

		virtual void draw(const float dt);
		virtual void update(const float dt);
		virtual void handleInput();

};

#endif
