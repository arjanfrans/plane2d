#ifndef GAME_STATE_MENU_H
#define GAME_STATE_MENU_H

#include <memory>

#include "game.h"
#include "game_state.h"

class GameStateMenu : public GameState {

    public:
        GameStateMenu(std::shared_ptr<Game> game);
        void update(const float dt);

};

#endif
