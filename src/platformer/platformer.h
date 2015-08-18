#pragma once

#include "../engine/game.h"

namespace platformer {
class Platformer : public pl::Game {

public:
private:
    void createStates();
    void createGameState();
};
}
