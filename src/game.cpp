
#include "engine/engine.h"
#include "game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "GL/gl.h"


namespace game {

    Game::Game()
    {}

    int Game::init() {
        // engine.init();
    }

    void Game::loop() {
        // engine.render();
    }

    int run() {
        Game game;
        game.init();
        game.loop();
        return 0;
    }
}

