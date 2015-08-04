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
    MenuView(std::shared_ptr<MenuState> state);
    std::shared_ptr<MenuState> state;
    void resize(float width, float height);
    void draw(sf::RenderWindow &window);
    std::vector<std::shared_ptr<ui::Button>> buttons;
    sf::View fixedView;
    sf::Sprite background;

private:
    void createBackground();
    void createButtons();
};
}

#endif
