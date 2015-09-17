#include <SFML/Graphics.hpp>
#include <tmxparser/Tmx.h>

namespace pl {

class TileMap {

public:
    TileMap();

private:
    sf::VertexArray vertices;
    void parseTmx(Tmx::Map &tmxMap);

};
}
