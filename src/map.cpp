#include <memory>
#include <vector>
#include <map>
#include "map.h"
#include "tile.h"
#include <fstream>
#include <iostream>

Map::Map()
    : width{ 0 }
    , height{ 0 }
    , tileSize{ 0 }
    , regions{ 1 }
{
}

Map::Map(const std::string& filename, int width, int height, std::map<std::string, Tile>& tileAtlas)
    : tileSize{ 8 }
{
    load(filename, width, height, tileAtlas);
}

void Map::load(const std::string& filename, int width, int height, 
        std::map<std::string, Tile>& tileAtlas)
{
    std::ifstream inputFile;
    inputFile.open(filename, std::ios::in | std::ios::binary);

    this->width = width;
    this->height = height;

    for (auto position = 0; position < (width * height); ++position) {
        resources.push_back(255);
        TileType type;
        inputFile.read((char*)&type, sizeof(int));
        switch (type) {
        case TileType::FOREST:
            tiles.push_back(tileAtlas.at("forest"));
            break;
        case TileType::RESIDENTIAL:
            tiles.push_back(tileAtlas.at("water"));
            break;
        case TileType::COMMERCIAL:
            tiles.push_back(tileAtlas.at("commercial"));
            break;
        case TileType::INDUSTRIAL:
            tiles.push_back(tileAtlas.at("industrial"));
            break;
        case TileType::ROAD:
            tiles.push_back(tileAtlas.at("road"));
            break;
        case TileType::VOID:
        case TileType::GRASS:
        default:
            tiles.push_back(tileAtlas.at("grass"));
            break;
        }
        Tile& tile = tiles.back();
        inputFile.read((char*)&tile.variant, sizeof(int));
        inputFile.read((char*)&tile.regions, sizeof(int) * 1);
        inputFile.read((char*)&tile.population, sizeof(double));
        inputFile.read((char*)&tile.storedGoods, sizeof(float));
    }

    inputFile.close();
    return;
}

void Map::save(const std::string& filename)
{
    std::ofstream outputFile;
    outputFile.open(filename, std::ios::out | std::ios::binary);

    for (auto tile : this->tiles) {
        outputFile.write((char*)&tile.type, sizeof(int));
        outputFile.write((char*)&tile.variant, sizeof(int));
        outputFile.write((char*)&tile.regions, sizeof(int) * 1);
        outputFile.write((char*)&tile.population, sizeof(double));
        outputFile.write((char*)&tile.storedGoods, sizeof(float));
    }

    outputFile.close();

    return;
}

void Map::draw(std::shared_ptr<sf::RenderWindow> window, float dt)
{
    for (int y = 0; y < this->height; ++y) {
        for (int x = 0; x < this->width; ++x) {
            sf::Vector2f pos;
            pos.x = (x - y) * this->tileSize + this->width * this->tileSize;
            pos.y = (x + y) * this->tileSize * 0.5;
            this->tiles[y * this->width + x].sprite.setPosition(pos);

            this->tiles[y * this->width + x].draw(window, dt);
        }
    }
    return;
}

void Map::updateDirection(TileType type)
{
    for (int y = 0; y < this->height; ++y) {
        for (int x = 0; x < this->width; ++x) {
            int pos = y * this->width + x;

            if (this->tiles[pos].type != type)
                continue;

            bool adjacentTiles[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };

            /* Check for adjacent tiles of the same type */
            if (x > 0 && y > 0)
                adjacentTiles[0][0] = (this->tiles[(y - 1) * this->width + (x - 1)].type == type);
            if (y > 0)
                adjacentTiles[0][1] = (this->tiles[(y - 1) * this->width + (x)].type == type);
            if (x < this->width - 1 && y > 0)
                adjacentTiles[0][2] = (this->tiles[(y - 1) * this->width + (x + 1)].type == type);
            if (x > 0)
                adjacentTiles[1][0] = (this->tiles[(y) * this->width + (x - 1)].type == type);
            if (x < width - 1)
                adjacentTiles[1][2] = (this->tiles[(y) * this->width + (x + 1)].type == type);
            if (x > 0 && y < this->height - 1)
                adjacentTiles[2][0] = (this->tiles[(y + 1) * this->width + (x - 1)].type == type);
            if (y < this->height - 1)
                adjacentTiles[2][1] = (this->tiles[(y + 1) * this->width + (x)].type == type);
            if (x < this->width - 1 && y < this->height - 1)
                adjacentTiles[2][2] = (this->tiles[(y + 1) * this->width + (x + 1)].type == type);

            /* Change the tile variant depending on the tile position */
            if (adjacentTiles[1][0] && adjacentTiles[1][2] && adjacentTiles[0][1] && adjacentTiles[2][1])
                this->tiles[pos].variant = 2;
            else if (adjacentTiles[1][0] && adjacentTiles[1][2] && adjacentTiles[0][1])
                this->tiles[pos].variant = 7;
            else if (adjacentTiles[1][0] && adjacentTiles[1][2] && adjacentTiles[2][1])
                this->tiles[pos].variant = 8;
            else if (adjacentTiles[0][1] && adjacentTiles[2][1] && adjacentTiles[1][0])
                this->tiles[pos].variant = 9;
            else if (adjacentTiles[0][1] && adjacentTiles[2][1] && adjacentTiles[1][2])
                this->tiles[pos].variant = 10;
            else if (adjacentTiles[1][0] && adjacentTiles[1][2])
                this->tiles[pos].variant = 0;
            else if (adjacentTiles[0][1] && adjacentTiles[2][1])
                this->tiles[pos].variant = 1;
            else if (adjacentTiles[2][1] && adjacentTiles[1][0])
                this->tiles[pos].variant = 3;
            else if (adjacentTiles[0][1] && adjacentTiles[1][2])
                this->tiles[pos].variant = 4;
            else if (adjacentTiles[1][0] && adjacentTiles[0][1])
                this->tiles[pos].variant = 5;
            else if (adjacentTiles[2][1] && adjacentTiles[1][2])
                this->tiles[pos].variant = 6;
            else if (adjacentTiles[1][0])
                this->tiles[pos].variant = 0;
            else if (adjacentTiles[1][2])
                this->tiles[pos].variant = 0;
            else if (adjacentTiles[0][1])
                this->tiles[pos].variant = 1;
            else if (adjacentTiles[2][1])
                this->tiles[pos].variant = 1;
        }
    }

    return;
}

void Map::depthFirstSearch(std::vector<TileType>& whitelist, sf::Vector2i position, int label, int regionType) {
    if (position.x < 0 || position.x > width) {
        return;
    }
    if (position.y < 0 || position.y >= height) {
        return;
    }
    if (tiles[position.y * (width + position.x)].regions[regionType] != 0) {
        return;
    }

    bool found = false;
    for(auto type : whitelist) {
        if(type == tiles[position.y * (width + position.x)].type) {
            found = true;
            break;
        }
    }

    if(!found) {
        return; 
    }

    tiles[position.y * (width + position.x)].regions[regionType] = label;

    depthFirstSearch(whitelist, position + sf::Vector2i(-1, 0), label, regionType);
    depthFirstSearch(whitelist, position + sf::Vector2i(0, 1), label, regionType);
    depthFirstSearch(whitelist, position + sf::Vector2i(1, 0), label, regionType);
    depthFirstSearch(whitelist, position + sf::Vector2i(0, -1), label, regionType);
}


void Map::findConnectedRegions(std::vector<TileType> whitelist, int regionType) {
    int regions = 1;

    for(auto& tile : tiles) {
        tile.regions[regionType] = 0;
    }

    for(int y = 0; y < height; ++y) {
        for(int x = 0; x < width; ++x) {
            bool found = false;
            for(auto type : whitelist) {
                if(type == tiles[y * (width + x)].type) {
                    found = true;
                    break;
                }
            }
            if(tiles[y * (width + x)].regions[regionType] == 0 && found) {
                depthFirstSearch(whitelist, sf::Vector2i(x, y), regions, regionType);
                regions = regions + 1;
            }
        } 
    }
    this->regions[regionType] = regions;
}
