#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include <vector>

#include "game.h"


class GameState {

    public:
        std::shared_ptr<Game> game;
        virtual void update(const float dt) = 0;

};

#endif
