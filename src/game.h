#ifndef GAME_H_
#define GAME_H_

#include "engine/engine.h"

namespace game {

    class Game {
        public:
            Game();
            int init();
            void loop();
        private:
            engine::Engine engine;
    };

    int run();

}

#endif
