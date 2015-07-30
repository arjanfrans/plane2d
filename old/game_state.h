#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "game.h"
#include "memory"

class GameState {
	public:
		std::shared_ptr<Game> game;

		virtual void draw(const float dt) = 0;
		virtual void update(const float dt) = 0;
		virtual void handleInput() = 0;

};

#endif
