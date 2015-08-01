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
    std::vector<std::shared_ptr<menu::Button>> buttons;

private:
    std::shared_ptr<sf::Font> font;
    void createButtons();
};
}

#endif
