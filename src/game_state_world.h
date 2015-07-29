#ifndef GAME_STATE_WORLD_H
#define GAME_STATE_WORLD_H

#include "memory"

#include "game_state.h"
#include "map.h"

enum class ActionState {
    NONE,
    PANNING
};

class GameStateWorld : public GameState {
	
	private:
        ActionState actionState;

		sf::View gameView;
		sf::View guiView;

        Map map;
        sf::Vector2i panningAnchor;
        float zoomLevel;

	public:
		GameStateWorld(std::shared_ptr<Game> gane);

		virtual void draw(const float dt);
		virtual void update(const float dt);
		virtual void handleInput();

};

#endif
