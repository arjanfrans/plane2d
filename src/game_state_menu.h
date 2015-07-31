#ifndef GAME_STATE_MENU_H
#define GAME_STATE_MENU_H

#include <memory>
#include <vector>

#include "game.h"
#include "game_state.h"
namespace input { class MenuInput; }
#include "input/menu_input.h"

class GameStateMenu : public GameState {

    public:
        GameStateMenu(std::shared_ptr<Game> game);
        void update(const float dt);
        void setInputs(std::vector<std::unique_ptr<input::MenuInput>> inputs);

    private:
        std::vector<std::unique_ptr<input::MenuInput>> inputs;
        void updateInputs();

};

#endif
