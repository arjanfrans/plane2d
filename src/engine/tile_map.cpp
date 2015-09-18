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

    for (int i = 0; i < tmxMap.GetNumTilesets(); ++i) {
        const auto &tmxTileset = *tmxMap.GetTileset(i);
        parseTileset(tmxTileset);
    }

    for (int i = 0; i < tmxMap.GetNumTileLayers(); ++i) {
        auto &tmxTileLayer = *tmxMap.GetTileLayer(i);
        parseTileLayer(tmxTileLayer);
    }
}

void TileMap::parseTileset(const Tmx::Tileset &tmxTileset) {
    auto imageSrc = tmxTileset.GetImage()->GetSource();
    auto imageWidth = tmxTileset.GetImage()->GetWidth();
    auto imageHeight = tmxTileset.GetImage()->GetHeight();

    for (auto &tile : tmxTileset.GetTiles()) {
    }

    LOG(INFO) << "Parsing tileset.";
    LOG(INFO) << "Image height: " + imageSrc;
}

void TileMap::parseTileLayer(const Tmx::TileLayer &tmxTileLayer) {
    auto layerWidth = tmxTileLayer.GetWidth();
    auto layerHeight = tmxTileLayer.GetHeight();

    for (int y = 0; y < layerHeight; ++y) {
        for (int x = 0; x < layerWidth; ++x) {
            auto tile = tmxTileLayer.GetTile(x, y);
            auto tilesetIndex = tmxTileLayer.GetTileTilesetIndex(x, y);

            if (tilesetIndex != -1) {
                LOG(INFO) << "Tile: " + std::to_string(x) + ", " + std::to_string(y);
                LOG(INFO) << "Tile ID: " + std::to_string(tile.id);
                LOG(INFO) << "Tile GID: " + std::to_string(tile.gid);
                LOG(INFO) << "Tileset id: " + std::to_string(tile.tilesetId);
                LOG(INFO) << "TilesetTileIndex: " + std::to_string(tilesetIndex);
            }
        }
    }
}
}
