#include <stack>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


#include "texture_manager.h"
#include "game.h"
#include "game_state.h"

Game::Game() 
{
	this->loadTextures();
	this->window.create(sf::VideoMode(800, 600), "Brecourt");
	this->window.setFramerateLimit(60);
	this->background.setTexture(this->textureManager.getReference("background"));
}

void Game::loadTextures() {
	this->textureManager.loadTexture("background", "data/graphics/background.png");
}

void Game::pushState(std::shared_ptr<GameState> state) {
	this->states.push(state);
	return;
}

void Game::popState() {
	this->states.pop();
	return;
}

void Game::changeState(std::shared_ptr<GameState> state) {
	if(!this->states.empty()) {
		popState();
	}
	pushState(move(state));
	return;
}

std::shared_ptr<GameState> Game::peekState() {
	if(this->states.empty()) {
		return nullptr;
	}
	return this->states.top();
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
