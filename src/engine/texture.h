#ifndef GAME_ENGINE_TEXTURE_H_
#define GAME_ENGINE_TEXTURE_H_

#include "memory"
#include "SDL2/SDL.h"

namespace game {
namespace engine {

    class Texture {

        private:
            std::unique_ptr<SDL_Surface, void (*)(SDL_Surface*)> surface_;
        public:
            Texture();
            int width_;
            int height_;
    };
}
}

#endif
