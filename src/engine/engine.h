#ifndef GAME_ENGINE_H_
#define GAME_ENGINE_H_

#include "renderer.h"

namespace game {
namespace engine {

    class Engine {

        public:
            Engine();
            void render();
            bool init();
        private:
            Renderer renderer_;
    };
}
}

#endif
