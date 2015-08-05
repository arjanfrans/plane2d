#pragma once

#include <memory>

#include "menu_state.h"
#include "../../ui/button.h"

#include "../view.h"
namespace pl {

class MenuState;

class MenuView : public View {

public:
    MenuView(std::shared_ptr<MenuState> state, float width, float height);
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
