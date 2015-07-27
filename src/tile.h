#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>

#include "animation_handler.h"

enum class TileType {
	VOID,
	GRASS,
	FOREST,
	WATER,
	RESIDENTIAL,
	COMMERCIAL,
	INDUSTRIAL,
	ROAD
};

class Tile {
	
	public:
		Tile();
		Tile(const int size, int height, std::shared_ptr<sf::Texture> texture,
				const std::vector<std::shared_ptr<Animation>>& animations, const TileType type,
				const int cost, const int maxPopulationPerLevel, const int maxLevels);

		AnimationHandler animationHandler;
		sf::Sprite sprite;
		TileType type;
		int variant;
		int regions[1];

		int cost;
		double population;
		int maxPopulationPerLevel;
		int maxLevels;
		float production;
		float storedGoods;

		void draw(std::shared_ptr<sf::RenderWindow> window, float dt);
		void update();
		std::string getCost();
		
		std::string tileTypeToStr(TileType type);

};

#endif
