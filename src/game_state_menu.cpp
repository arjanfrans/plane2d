#include "memory"

#include "SFML/Graphics.hpp"

#include "game_state.h"
#include "game_state_menu.h"
#include "game_state_world.h"

GameStateMenu::GameStateMenu(std::shared_ptr<Game> game)
{
	this->game = game;
    sf::Vector2f position = sf::Vector2f(this->game->window->getSize());
	this->view.setSize(position);
	position = position * 0.5f;
	this->view.setCenter(position);
}


void GameStateMenu::loadgame() {
	this->game->pushState(std::shared_ptr<GameStateWorld>{new GameStateWorld(this->game)});
	return;
}

void GameStateMenu::draw(const float dt) {
	this->game->window->setView(this->view);
	this->game->window->clear(sf::Color::Black);
	this->game->window->draw(this->game->background);
	return;
}

void GameStateMenu::update(const float dt) {

}

void GameStateMenu::handleInput() {
	sf::Event event;

	while(this->game->window->pollEvent(event)) {
		switch(event.type) {
			case sf::Event::Closed: {
				this->game->window->close();
				break;
			}
			case sf::Event::Resized: {
				this->view.setSize(event.size.width, event.size.height);
				auto backgroundPosition = this->game->window->mapPixelToCoords(sf::Vector2i(0, 0));
				this->game->background.setPosition(backgroundPosition);
				auto scaleX = float(event.size.width) / float(this->game->background.getTexture()->getSize().x);
				auto scaleY = float(event.size.height) / float(this->game->background.getTexture()->getSize().y);
				this->game->background.setScale(scaleX, scaleY);
				break;
			 }
			case sf::Event::KeyPressed: {
				if(event.key.code == sf::Keyboard::Escape) {
					this->game->window->close();
				} else if (event.key.code == sf::Keyboard::Space) {
					this->loadgame();
				}
				break;
			}
			default:
				break;
		}
	}
	return;
}
