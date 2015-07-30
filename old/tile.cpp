#include <memory>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "tile.h"

Tile::Tile() {
}

Tile::Tile(const int size, int height, std::shared_ptr<sf::Texture> texture,
				const std::vector<std::shared_ptr<Animation>>& animations, const TileType type,
				const int cost, const int maxPopulationPerLevel, const int maxLevels)
: type{type}, cost{cost}, maxPopulationPerLevel{maxPopulationPerLevel},
	maxLevels{maxLevels}
{
	sprite.setOrigin(sf::Vector2f(0.0f, size * (height - 1)));
	sprite.setTexture(*texture.get());
	animationHandler.frameSize = sf::IntRect(0, 0, size * 2, size * height);
	
	for(auto animation : animations) {
		animationHandler.addAnimation(animation);
	}
	animationHandler.update(0.0f);
}

void Tile::draw(std::shared_ptr<sf::RenderWindow> window, float dt) {
	animationHandler.changeAnimation(variant);

	animationHandler.update(dt);
	sprite.setTextureRect(animationHandler.bounds);
	window->draw(sprite);
	return;
}

void Tile::update() {
	if((type == TileType::RESIDENTIAL || type == TileType::COMMERCIAL || type == TileType::INDUSTRIAL) 
			&& population == maxPopulationPerLevel * (variant + 1) && variant < maxLevels) {
		if(rand() % static_cast<int>(1e4) < 1e2 / (variant + 1)) {
			variant = variant + 1;	
		}
	}
	return;
}

std::string Tile::getCost() {
	return std::to_string(cost);
}

std::string Tile::tileTypeToStr(TileType type) {
	switch(type) {
		case TileType::VOID:
			return "Void";
		case TileType::GRASS:   
			return "Flatten";
		case TileType::FOREST:        
			return "Forest";
		case TileType::WATER:        
			return "Water";
		case TileType::RESIDENTIAL:  
			return "Residential Zone";
		case TileType::COMMERCIAL: 
			return "Commercial Zone";
		case TileType::INDUSTRIAL:    
			return "Industrial Zone";
		default:
			return "Unknown";
	}
}
