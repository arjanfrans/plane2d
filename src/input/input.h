#ifndef INPUT_INPUT_H
#define INPUT_INPUT_H

#include <memory>

#include "../game_state.h"

namespace input {

class Input {

    public:
        virtual void update(const float dt) = 0;
        std::shared_ptr<GameState> state; 

};

}

#endif
