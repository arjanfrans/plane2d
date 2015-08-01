#ifndef GAME_STATE_MENU_H
#define GAME_STATE_MENU_H

#include <memory>
#include <vector>
#include <map>

#include "game.h"
#include "game_state.h"

namespace input {
class MenuInput;
}
namespace view {
class MenuView;
}
#include "input/menu_input.h"
#include "view/menu_view.h"

enum MenuItem { START = 0, OPTIONS = 1, EXIT = 2 };

class GameStateMenu : public GameState {

public:
    GameStateMenu(std::shared_ptr<Game> game);
    void update(const float dt);
    void setInputs(std::vector<input::MenuInput> inputs);
    void setViews(std::vector<view::MenuView> view);
    std::vector<std::string> items;
    void moveUp();
    void moveDown();
    void select();
    int selectedItemIndex;

private:
    std::vector<input::MenuInput> inputs;
    std::vector<view::MenuView> views;
    void updateInputs();
    void updateViews();
};

#endif
