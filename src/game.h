#ifndef GAME_H_
#define GAME_H_

#include "SFML/Graphics.hpp"
#include "stack"
#include "memory"
#include "texture_manager.h"

class GameState;

class Game {
	private:
		void loadTextures();

	public:
		Game();
		~Game();

		sf::Sprite background;
		std::stack<std::shared_ptr<GameState>> states;
		sf::RenderWindow window;
		TextureManager textureManager;

		void pushState(std::shared_ptr<GameState> state);
		void popState();
		void changeState(std::shared_ptr<GameState> state);
		std::shared_ptr<GameState> peekState();

		void gameLoop();

};

#endif
