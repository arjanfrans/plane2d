#ifndef GAME_ENGINE_ENGINE_H_
#define GAME_ENGINE_ENGINE_H_

#include "renderer.h"
#include "window.h"

namespace game {
namespace engine {

    class Engine {

        public:
            Engine();
            void render();
            bool init();
        private:
            Window window_;
            Renderer renderer_;
    };
}
}

#endif
