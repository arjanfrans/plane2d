#include <memory>

#include <SFML/Graphics.hpp>

#include "game_state.h"
#include "game_state_world.h"

GameStateWorld::GameStateWorld(std::shared_ptr<Game> game) {
	this->game = game;
	sf::Vector2f position = sf::Vector2f(this->game->window->getSize());
	this->guiView.setSize(position);
	this->gameView.setSize(position);
	position = position * 0.5f;
	this->guiView.setCenter(position);
	this->gameView.setCenter(position);

    map = Map("data/maps/city_map.dat", 64, 64, game->tileAtlas);
    zoomLevel = 1.0f;

    sf::Vector2f center(map.width, map.height * 0.5);
    center = center * static_cast<float>(map.tileSize);
    gameView.setCenter(center);

    actionState = ActionState::NONE;
}

void GameStateWorld::draw(const float dt) {
	this->game->window->clear(sf::Color::Black);

    this->game->window->setView(guiView);
	this->game->window->draw(this->game->background);

    this->game->window->setView(gameView);
    map.draw(game->window, dt);
	return;
}

void GameStateWorld::update(const float dt) {
	return;
}

void GameStateWorld::handleInput() {
	sf::Event event;

	while(this->game->window->pollEvent(event)) {
		switch(event.type) {
			case sf::Event::Closed: {
				this->game->window->close();
				break;
			}
			case sf::Event::Resized: {
				this->gameView.setSize(event.size.width, event.size.height);
				this->guiView.setSize(event.size.width, event.size.height);
                gameView.zoom(zoomLevel);
				auto backgroundPosition = this->game->window->mapPixelToCoords(sf::Vector2i(0, 0), this->guiView);
				this->game->background.setPosition(backgroundPosition);
				auto scaleX = float(event.size.width) / float(this->game->background.getTexture()->getSize().x);
				auto scaleY = float(event.size.height) / float(this->game->background.getTexture()->getSize().y);
				this->game->background.setScale(scaleX, scaleY);
				break;
			}
            case sf::Event::MouseMoved: {
                if(actionState == ActionState::PANNING) {
                    sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition(*game->window) - panningAnchor);
                    gameView.move(-1.0f * position * zoomLevel);
                    panningAnchor = sf::Mouse::getPosition(*game->window);
                }
                break;
            }
            case sf::Event::MouseButtonPressed: {
                if(event.mouseButton.button == sf::Mouse::Middle) {
                    if(actionState != ActionState::PANNING) {
                        actionState = ActionState::PANNING;
                        panningAnchor = sf::Mouse::getPosition(*game->window);
                    }
                }
                break;
            }
            case sf::Event::MouseButtonReleased: {
                if(event.mouseButton.button == sf::Mouse::Middle) {
                    actionState = ActionState::NONE;
                }
                break;
            }
            case sf::Event::MouseWheelMoved: {
                if(event.mouseWheel.delta < 0) {
                    gameView.zoom(2.0f);
                    zoomLevel = zoomLevel * 2.0f;
                } else {
                    gameView.zoom(0.5f);
                    zoomLevel = zoomLevel * 0.5f;
                }
                break;
            }
			default:
				break;
		}
	}

	return;
}
