#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <tmxparser/Tmx.h>
#include "engine.h"

namespace pl {

struct Tileset {
    std::string imageSource;
    int imageWidth;
    int imageHeight;
    int tileWidth;
    int tileHeight;
    std::vector<Tmx::Tile> tiles;
};

class TileMap : public sf::Drawable, public sf::Transformable {

public:
    TileMap(sf::Texture& tilesetTexture);
    int width = 0;
    int height = 0;
    int tileWidth = 0;
    int tileHeight = 0;
    void parseTmx(Tmx::Map &tmxMap);
    sf::VertexArray vertices;
    sf::Texture &tilesetTexture;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const; 
    void parseTileset(const Tmx::Tileset &tmxTileset);
    void parseTileLayer(std::vector<Tileset> tilesets, const Tmx::TileLayer *tmxTileLayer);
};
}
