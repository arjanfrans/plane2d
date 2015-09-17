#include <memory>

#include <SFML/Graphics.hpp>
#include <tmxparser/Tmx.h>

namespace pl {

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
    void parseTileset(Tmx::Tileset &tmxTileset);
};
}
