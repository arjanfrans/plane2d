#include <memory>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "texture_manager.h"

TextureManager::TextureManager() {
}

void TextureManager::loadTexture(const std::string& name, const std::string& filename) {
	sf::Texture texture;
	texture.loadFromFile(filename);

	this->textures[name] = texture;
	return;

}

sf::Texture& TextureManager::getReference(const std::string& texture)
{
	return this->textures.at(texture);
}
