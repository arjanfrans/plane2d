#include <iostream>

#include "game_state.h"
#include "game_state_menu.h"
#include "game_manager.h"

#include "utils/logger.h"

INITIALIZE_LOGGER

int main() {
    GameManager manager;
    manager.start();
    return 0;
}
