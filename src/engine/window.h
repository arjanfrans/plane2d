#ifndef GAME_ENGINE_WINDOW_H_
#define GAME_ENGINE_WINDOW_H_

#include "SDL2/SDL.h"
#include "memory"

namespace game {
namespace engine {

    class Window {

        private:
            std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> window_;
            std::unique_ptr<SDL_Surface, void (*)(SDL_Surface*)> surface_;
        public:
            Window();
            int width_;
            int height_;
            bool init();
    };

}
}

#endif
