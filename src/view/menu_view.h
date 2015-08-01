#ifndef VIEW_MENU_VIEW_H
#define VIEW_MENU_VIEW_H

#include <memory>

class GameStateMenu;
#include "../game_state_menu.h"
#include "menu/button.h"

namespace view {

class MenuView {

public:
    MenuView(std::shared_ptr<GameStateMenu> state);
    std::shared_ptr<GameStateMenu> state;
    void draw(sf::RenderWindow &window);
    // std::vector<MouseListener&> mouseListeners;

private:
    std::shared_ptr<sf::Font> font;
    std::vector<menu::Button> buttons;
    void createButtons();
};
}

#endif
