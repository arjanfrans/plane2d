#ifndef GAME_H_
#define GAME_H_

#include "SFML/Graphics.hpp"
#include <map>
#include <stack>
#include <memory>
#include "tile.h"
#include "texture_manager.h"

class GameState;

class Game {
private:
    void loadTextures();
    void loadTiles();

public:
    Game();

    const static int tileSize = 8;
    std::map<std::string, Tile> tileAtlas;

    sf::Sprite background;
    std::stack<std::shared_ptr<GameState> > states;
    std::shared_ptr<sf::RenderWindow> window = nullptr;
    TextureManager textureManager;

    void pushState(std::shared_ptr<GameState> state);
    void popState();
    void changeState(std::shared_ptr<GameState> state);
    std::shared_ptr<GameState> peekState();



    void gameLoop();
};

#endif
