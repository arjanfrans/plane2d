
#include "engine/engine.h"
#include "game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "GL/gl.h"
#include "stdio.h"


namespace game {

    Game::Game()
    {}

    bool Game::init() {
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("SDL_Error: %s\n", SDL_GetError());
        }
        return engine.init();
    }

    void Game::loop() {
        engine.render();
    }

    int run() {
        Game game;
        if(game.init()) {
            game.loop();
            SDL_Quit();
            return 0;
        }
        printf("Something went wrong");
        SDL_Quit();
        return 1;
    }
}

