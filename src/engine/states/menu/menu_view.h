#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <memory>
#include <string>

#include "menu_state.h"
#include "../../ui/button.h"

namespace pl {

class MenuState;

class MenuView {

public:
    MenuView(std::shared_ptr<MenuState> state, std::string fontName);
    std::shared_ptr<MenuState> state;
    void draw(sf::RenderWindow &window);
    std::vector<std::shared_ptr<ui::Button>> buttons;

private:
    std::shared_ptr<sf::Font> font;
    void createButtons();
};
}

#endif
