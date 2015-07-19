#include <stack>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


#include "game.h"
#include "game_state.h"

Game::Game() 
{
	this->window.create(sf::VideoMode(800, 600), "Brecourt");
	this->window.setFramerateLimit(60);
}

void Game::pushState(std::unique_ptr<GameState> state) {
	this->states.push(state);
	return;
}

void Game::popState() {
	this->states.pop();
	return;
}

void Game::changeState(std::unique_ptr<GameState> state) {
	if(!this->states.empty()) {
		popState();
	}
	pushState(move(state));
	return;
}

std::unique_ptr<GameState> Game::peekState() {
	if(this->states.empty()) {
		return nullptr;
	}
	return move(this->states.top());
}

void Game::gameLoop() {
	sf::Clock clock;

	while(this->window.isOpen()) {
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if(peekState() != nullptr) {
			peekState()->handleInput();
			peekState()->update(dt);
			this->window.clear(sf::Color::Black);
			peekState()->draw(dt);
			this->window.display();
		}
	}
}
