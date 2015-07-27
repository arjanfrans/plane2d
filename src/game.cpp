#include <stack>
#include <map>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "tile.h"
#include "animation_handler.h"
#include "texture_manager.h"
#include "game.h"
#include "game_state.h"

Game::Game() 
{
	loadTextures();
	loadTiles();
	window.create(sf::VideoMode(800, 600), "Brecourt");
	window.setFramerateLimit(60);
	background.setTexture(*textureManager.getReference("background"));
}

void Game::loadTextures() {
	textureManager.loadTexture("grass", "data/graphics/grass.png");
	textureManager.loadTexture("forest", "data/graphics/forest.png");
	textureManager.loadTexture("water", "data/graphics/water.png");
	textureManager.loadTexture("residential", "data/graphics/residential.png");
	textureManager.loadTexture("commercial", "data/graphics/commercial.png");
	textureManager.loadTexture("industrial", "data/graphics/industrial.png");
	textureManager.loadTexture("road", "data/graphics/road.png");

	textureManager.loadTexture("background", "data/graphics/background.png");
}

void Game::pushState(std::shared_ptr<GameState> state) {
	states.push(state);
	return;
}

void Game::popState() {
	states.pop();
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

void Game::loadTiles() {
	auto staticAnim = std::make_shared<Animation>(0, 0, 1.0f);
	tileAtlas["grass"] =
        Tile(tileSize, 1, textureManager.getReference("grass"),
            { staticAnim },
            TileType::GRASS, 50, 0, 1);
    tileAtlas["forest"] =
        Tile(tileSize, 1, textureManager.getReference("forest"),
            { staticAnim },
            TileType::FOREST, 100, 0, 1);   
    tileAtlas["water"] =
        Tile(tileSize, 1, textureManager.getReference("water"),
            { std::make_shared<Animation>(0, 3, 0.5f),
            std::make_shared<Animation>(0, 3, 0.5f),
            std::make_shared<Animation>(0, 3, 0.5f) },
            TileType::WATER, 0, 0, 1);
    tileAtlas["residential"] =
        Tile(tileSize, 2, textureManager.getReference("residential"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim },
            TileType::RESIDENTIAL, 300, 50, 6);
    tileAtlas["commercial"] =
        Tile(tileSize, 2, textureManager.getReference("commercial"),
            { staticAnim, staticAnim, staticAnim, staticAnim},
            TileType::COMMERCIAL, 300, 50, 4);
    tileAtlas["industrial"] =
        Tile(tileSize, 2, textureManager.getReference("industrial"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim },
            TileType::INDUSTRIAL, 300, 50, 4);
    tileAtlas["road"] =
        Tile(tileSize, 1, textureManager.getReference("road"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim },
            TileType::ROAD, 100, 0, 1);
    return;
}
