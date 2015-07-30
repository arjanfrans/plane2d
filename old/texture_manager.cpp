#include <memory>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "texture_manager.h"

TextureManager::TextureManager() {
}

void TextureManager::loadTexture(const std::string& name, const std::string& filename) {
	auto texture = std::make_shared<sf::Texture>();
	texture->loadFromFile(filename);

	this->textures.emplace(name, texture);
	return;

}

std::shared_ptr<sf::Texture> TextureManager::getReference(const std::string& texture)
{
	return textures.at(texture);
}
