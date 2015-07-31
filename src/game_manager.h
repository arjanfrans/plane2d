#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "game.h"

class GameManager {

    public:
        void start();
 
    private:
        std::shared_ptr<Game> game;
        void createMenuState();

};

#endif
