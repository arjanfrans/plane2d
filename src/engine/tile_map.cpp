#include <string>
#include <memory>
#include "tile_map.h"
#include "utils/logger.h"

namespace pl {

TileMap::TileMap(){};

void TileMap::parseTmx(Tmx::Map &tmxMap) {
    this->width = tmxMap.GetWidth();
    this->height = tmxMap.GetHeight();
    this->tileWidth = tmxMap.GetTileWidth();
    this->tileHeight = tmxMap.GetTileHeight();

    LOG(INFO) << "Number of tilesets: " + std::to_string(tmxMap.GetNumTilesets());

    for(int i = 0; i < tmxMap.GetNumTilesets(); ++i) {
        auto tmxTileset = *tmxMap.GetTileset(i);
        parseTileset(tmxTileset);
    }
}

void TileMap::parseTileset(Tmx::Tileset &tmxTileset) {
    auto imageHeight = tmxTileset.GetImage()->GetHeight();
    LOG(INFO)<< "Parsing tileset.";
    LOG(INFO)<< "Image height: " + std::to_string(imageHeight);
}
}
