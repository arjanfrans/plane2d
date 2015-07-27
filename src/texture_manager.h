#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <memory>

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager {

	private:
		std::map<std::string, std::shared_ptr<sf::Texture>> textures;

	public:
		TextureManager();
		void loadTexture(const std::string& name, const std::string& filename);
		std::shared_ptr<sf::Texture> getReference(const std::string& texture);
};

#endif
