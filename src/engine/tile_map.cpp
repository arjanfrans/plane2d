#include <string>
#include <memory>
#include <vector>
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

    std::vector<Tileset> tilesets;

    for (int i = 0; i < tmxMap.GetNumTilesets(); ++i) {
        const Tmx::Tileset *tmxTileset = tmxMap.GetTileset(i);
        Tileset tileset;
        tileset.imageSource = tmxTileset->GetImage()->GetSource();
        tileset.imageWidth = tmxTileset->GetImage()->GetWidth();
        tileset.imageHeight = tmxTileset->GetImage()->GetHeight();
        tileset.tileWidth = tmxTileset->GetTileWidth();
        tileset.tileHeight = tmxTileset->GetTileHeight();
        tilesets.push_back(tileset);
    }

    for (int i = 0; i < tmxMap.GetNumTileLayers(); ++i) {
        const Tmx::TileLayer *tmxTileLayer = tmxMap.GetTileLayer(i);
        parseTileLayer(tilesets, tmxTileLayer);
    }
}
//
// void TileMap::parseTileset(const Tmx::Tileset &tmxTileset) {
//     auto imageSrc = tmxTileset.GetImage()->GetSource();
//     auto imageWidth = tmxTileset.GetImage()->GetWidth();
//     auto imageHeight = tmxTileset.GetImage()->GetHeight();
//
//     for (auto &tile : tmxTileset.GetTiles()) {
//     }
//
//     LOG(INFO) << "Parsing tileset.";
//     LOG(INFO) << "Image height: " + imageSrc;
// }

void TileMap::parseTileLayer(std::vector<Tileset> tilesets, const Tmx::TileLayer *tmxTileLayer) {
    auto layerWidth = tmxTileLayer->GetWidth();
    auto layerHeight = tmxTileLayer->GetHeight();

    LOG(INFO) << "Layer size: " + std::to_string(layerWidth) + ", " + std::to_string(layerHeight);

    this->vertices.setPrimitiveType(sf::Quads);
    this->vertices.resize(layerWidth * layerHeight * 4);

    for (int x = 0; x < layerWidth; ++x) {
        for (int y = 0; y < layerHeight; ++y) {
            auto tile = tmxTileLayer->GetTile(x, y);
            auto tilesetIndex = tmxTileLayer->GetTileTilesetIndex(x, y);

            if (tilesetIndex != -1) {
                LOG(INFO) << "Tileset id: " + std::to_string(tilesetIndex);

                auto &tileset = tilesets.at(0);

                LOG(INFO) << "Tileset image: " + tileset.imageSource;

                int tilesetWidth = tileset.imageWidth;
                LOG(INFO) << "Tileset width: " + std::to_string(tilesetWidth);

                int tilesetHeight = tileset.imageHeight;
                LOG(INFO) << "Tileset height: " + std::to_string(tilesetHeight);

                auto tileWidth = tileset.tileWidth;
                auto tileHeight = tileset.tileHeight;
                LOG(INFO) << "Tile position: " + std::to_string(x) + ", " + std::to_string(y);
                LOG(INFO) << "Tile size: " + std::to_string(tileWidth) + ", " +
                                 std::to_string(tileHeight);

                LOG(INFO) << "Tile ID: " + std::to_string(tile.id);

                LOG(INFO) << "Tile GID: " + std::to_string(tile.gid);
                LOG(INFO) << "TilesetTileIndex: " + std::to_string(tilesetIndex);

                sf::Vertex *quad = &this->vertices[x * y * 4];

                auto tu = tile.id % (tilesetWidth / tileWidth);
                auto tv = tile.id / (tilesetWidth / tileWidth);

                quad[0].position = sf::Vector2f(x * tileWidth, y * tileHeight);
                quad[1].position = sf::Vector2f((x + 1) * tileWidth, y * tileHeight);
                quad[2].position = sf::Vector2f((x + 1) * tileWidth, (y + 1) * tileHeight);
                quad[3].position = sf::Vector2f(x * tileWidth, (y + 1) * tileHeight);

                quad[0].texCoords = sf::Vector2f(tu * tileWidth, tv * tileHeight);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileWidth, tv * tileHeight);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileWidth, (tv + 1) * tileHeight);
                quad[3].texCoords = sf::Vector2f(tu * tileWidth, (tv + 1) * tileHeight);
            }
        }
    }
    LOG(INFO) << "Out of loop";
}
}
