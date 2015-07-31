#ifndef VIEW_MENU_VIEW_H
#define VIEW_MENU_VIEW_H

#include <memory>

class GameStateMenu;
#include "../game_state_menu.h"

namespace view {

class MenuView {

    public:
        MenuView(std::shared_ptr<GameStateMenu> state);
        std::shared_ptr<GameStateMenu> state;
        void draw();

    private:
        sf::Font font;
};

}

#endif
