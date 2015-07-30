#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include "tile.h"

class Map {

	private:
		void depthFirstSearch(std::vector<TileType>& whitelist, sf::Vector2i position, int label, int regionType = 0);

	public:
		Map();
		Map(const std::string& filename, int width, int height, std::map<std::string, std::shared_ptr<Tile>>& tileAtlas);

		int width;
		int height;
		std::vector<std::shared_ptr<Tile>> tiles;
		std::vector<int> resources;
		int tileSize;
        std::vector<char> selected;
		int selectedCount;
		int regions[1];

		void select(sf::Vector2i start, sf::Vector2i end, std::vector<TileType> blacklist);
		void clearSelected();

		void load(const std::string& filename, int width, int height, std::map<std::string,
				std::shared_ptr<Tile>>& tileAtlas);

		void save(const std::string& filename);

		void draw(std::shared_ptr<sf::RenderWindow> window, float dt);

		void findConnectedRegions(std::vector<TileType> whitelist, int regionType = 0);

		void updateDirection(TileType type);
};

#endif
