#ifndef GAME_ENGINE_RENDERER_H_
#define GAME_ENGINE_RENDERER_H_

#include "SDL2/SDL.h"


namespace game {
namespace engine {

    class Renderer {

        private:
            SDL_Window* window_;
            SDL_Surface* surface_;

        public:
            Renderer();
            ~Renderer();
            int screen_width_;
            int screen_height_;
            bool init();
            void render();
    };

}
}

#endif
