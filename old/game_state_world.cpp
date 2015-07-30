#include <memory>

#include <SFML/Graphics.hpp>

#include "game_state.h"
#include "game_state_world.h"

GameStateWorld::GameStateWorld(std::shared_ptr<Game> game) {
	game = game;
	sf::Vector2f position = sf::Vector2f(game->window->getSize());
	guiView.setSize(position);
	gameView.setSize(position);
	position = position * 0.5f;
	guiView.setCenter(position);
	gameView.setCenter(position);

    map = Map("data/maps/city_map.dat", 64, 64, game->tileAtlas);
    zoomLevel = 1.0f;

    sf::Vector2f center(map.width, map.height * 0.5);
    center = center * static_cast<float>(map.tileSize);
    gameView.setCenter(center);

    selectionStart = sf::Vector2i(0,0);
    selectionEnd = sf::Vector2i(0,0);
    currentTile = std::shared_ptr<Tile>{game->tileAtlas.at("grass")};
    actionState = ActionState::NONE;
}

void GameStateWorld::draw(const float dt) {
	game->window->clear(sf::Color::Black);

    game->window->setView(guiView);
	game->window->draw(this->game->background);

    game->window->setView(gameView);
    map.draw(game->window, dt);
	return;
}

void GameStateWorld::update(const float dt) {
	return;
}

void GameStateWorld::handleInput() {
	sf::Event event;

	while(game->window->pollEvent(event)) {
    return;
		switch(event.type) {
			case sf::Event::Closed: {
				game->window->close();
				break;
			}
			case sf::Event::Resized: {
				gameView.setSize(event.size.width, event.size.height);
				guiView.setSize(event.size.width, event.size.height);
                gameView.zoom(zoomLevel);
				auto backgroundPosition = game->window->mapPixelToCoords(sf::Vector2i(0, 0), this->guiView);
				game->background.setPosition(backgroundPosition);
				auto scaleX = float(event.size.width) / float(game->background.getTexture()->getSize().x);
				auto scaleY = float(event.size.height) / float(game->background.getTexture()->getSize().y);
				game->background.setScale(scaleX, scaleY);
				break;
			}
            case sf::Event::MouseMoved: {
                auto mousePosition = sf::Mouse::getPosition(*game->window);
                if(actionState == ActionState::PANNING) {
                    sf::Vector2f position = sf::Vector2f(mousePosition - panningAnchor);
                    gameView.move(-1.0f * position * zoomLevel);
                    panningAnchor = mousePosition; 
                } else if(actionState == ActionState::SELECTING) {
                    sf::Vector2f pos = game->window->mapPixelToCoords(mousePosition, gameView);
                    selectionEnd.x = pos.y / (map.tileSize) + pos.x / (2 * map.tileSize) - map.width * 0.5 - 0.5;
                    selectionEnd.y = pos.y / (map.tileSize) - pos.x / (2 * map.tileSize) + map.width * 0.5 + 0.5;

                    map.clearSelected();
                    if(currentTile->type == TileType::GRASS) {
                        map.select(selectionStart, selectionEnd, { currentTile->type, TileType::WATER});
                    } else {
                        map.select(selectionStart, selectionEnd, {
                            currentTile->type, TileType::FOREST,
                            TileType::WATER, TileType::ROAD, TileType::RESIDENTIAL,
                            TileType::COMMERCIAL, TileType::INDUSTRIAL
                        });
                    }
                }
                break;
            }
            case sf::Event::MouseButtonPressed: {
                auto mousePosition = sf::Mouse::getPosition(*game->window);
                if(event.mouseButton.button == sf::Mouse::Middle) {
                    if(actionState != ActionState::PANNING) {
                        actionState = ActionState::PANNING;
                        panningAnchor = mousePosition; 
                    }
                }
                else if(event.mouseButton.button == sf::Mouse::Left) {
                    if(actionState != ActionState::SELECTING) {
                        actionState = ActionState::SELECTING;
                        sf::Vector2f pos = game->window->mapPixelToCoords(mousePosition, gameView);
                        selectionStart.x = pos.y / (map.tileSize) + pos.x / (2 * map.tileSize) - map.width * 0.5 - 0.5;
                        selectionStart.y = pos.y / (map.tileSize) - pos.x / (2 * map.tileSize) + map.width * 0.5 + 0.5;
                    }
                }
                else if(event.mouseButton.button == sf::Mouse::Right)
                {
                    if(actionState == ActionState::SELECTING) {
                        actionState = ActionState::NONE;
                        map.clearSelected();
                    }
                }

                break;
            }
            case sf::Event::MouseButtonReleased: {
                if(event.mouseButton.button == sf::Mouse::Middle) {
                    actionState = ActionState::NONE;
                } else if(event.mouseButton.button == sf::Mouse::Left) {
                    if(actionState == ActionState::SELECTING) {
                        actionState = ActionState::NONE;
                        map.clearSelected();
                    }
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
