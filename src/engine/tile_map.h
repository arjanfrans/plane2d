#include <memory>

#include <SFML/Graphics.hpp>
#include <tmxparser/Tmx.h>

namespace pl {

struct Tileset {
    std::string imageSource;
    int imageWidth;
    int imageHeight;
    int tileWidth;
    int tileHeight;
    std::vector<Tmx::Tile> tiles;
};

struct TileLayer {
    int width;
    int height;
};

class TileMap {

public:
    TileMap();
    int width = 0;
    int height = 0;
    int tileWidth = 0;
    int tileHeight = 0;
    void parseTmx(Tmx::Map &tmxMap);
    sf::VertexArray vertices;

private:
    void parseTileset(const Tmx::Tileset &tmxTileset);
    void parseTileLayer(std::vector<Tileset> tilesets, const Tmx::TileLayer *tmxTileLayer);
};
}
