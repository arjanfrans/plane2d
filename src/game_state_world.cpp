#include <memory>

#include <SFML/Graphics.hpp>

#include "game_state.h"
#include "game_state_world.h"

GameStateWorld::GameStateWorld(std::shared_ptr<Game> game) {
	this->game = game;
	sf::Vector2f position = sf::Vector2f(this->game->window.getSize());
	this->guiView.setSize(position);
	this->gameView.setSize(position);
	position = position * 0.5f;
	this->guiView.setCenter(position);
	this->gameView.setCenter(position);
}

void GameStateWorld::draw(const float dt) {
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->game->background);
	return;
}

void GameStateWorld::update(const float dt) {
	return;
}

void GameStateWorld::handleInput() {
	sf::Event event;

	while(this->game->window.pollEvent(event)) {
		switch(event.type) {
			case sf::Event::Closed: {
				this->game->window.close();
				break;
			}
			case sf::Event::Resized: {
				this->gameView.setSize(event.size.width, event.size.height);
				this->guiView.setSize(event.size.width, event.size.height);
				auto backgroundPosition = this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView);
				this->game->background.setPosition(backgroundPosition);
				auto scaleX = float(event.size.width) / float(this->game->background.getTexture()->getSize().x);
				auto scaleY = float(event.size.height) / float(this->game->background.getTexture()->getSize().y);
				this->game->background.setScale(scaleX, scaleY);
				break;
			}
			default:
				break;
		}
	}

	return;
}
