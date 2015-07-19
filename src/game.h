#ifndef GAME_H_
#define GAME_H_

#include "SFML/Graphics.hpp"
#include "stack"
#include "memory"

class GameState;

class Game {
	public:
		Game();
		~Game();

		std::stack<std::unique_ptr<GameState>> states;
		sf::RenderWindow window;

		void pushState(std::unique_ptr<GameState> state);
		void popState();
		void changeState(std::unique_ptr<GameState> state);
		std::unique_ptr<GameState> peekState();

		void gameLoop();

};

#endif
