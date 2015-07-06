#ifndef GAME_ENGINE_RENDERER_H_
#define GAME_ENGINE_RENDERER_H_

#include "SDL2/SDL.h"
#include "memory"

namespace game {
namespace engine {

    class Renderer {

        private:
            std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> window_;
            std::unique_ptr<SDL_Surface, void (*)(SDL_Surface*)> surface_;
        public:
            Renderer();
            int screen_width_;
            int screen_height_;
            bool init();
            void render();
    };

}
}

#endif
