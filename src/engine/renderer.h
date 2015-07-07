#ifndef GAME_ENGINE_RENDERER_H_
#define GAME_ENGINE_RENDERER_H_

#include "SDL2/SDL.h"
#include "memory"

namespace game {
namespace engine {

    class Renderer {

        public:
            Renderer();
            bool init();
            void render();
    };

}
}

#endif
