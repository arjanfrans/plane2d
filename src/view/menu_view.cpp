#include <memory>
#include "menu_view.h"

#include "menu/button.h"

#include "../utils/logger.h"

namespace view {

MenuView::MenuView(std::shared_ptr<GameStateMenu> state) : font{std::make_shared<sf::Font>()} {
    this->state = state;
    if (!font->loadFromFile("data/fonts/font.ttf")) {
        this->state->game->window.close();
        LOG(ERROR) << "Unable to load font.";
        exit(EXIT_FAILURE);
    }
    createButtons();
}

void MenuView::createButtons() {
    auto &window = this->state->game->window;
    sf::Vector2u size{window.getSize()};
    auto itemCount = this->state->items.size();
    auto itemHeight = size.y / itemCount;
    for (auto i = 0; i < itemCount; ++i) {
        auto item = this->state->items.at(i);
        float x = size.x / 2;
        float y = (itemHeight / 2) * i;
        sf::Vector2f position{x, y};
        menu::Button button{item, position, this->font, sf::Color::Green, sf::Color::Cyan, 24};
        this->buttons.push_back(button);
    }
    return;
}

void MenuView::draw(sf::RenderWindow &window) {
    for (int i = 0; i < this->buttons.size(); ++i) {
        auto &button = this->buttons.at(i);
        if (i == this->state->selectedItemIndex) {
            button.setActive(true);
        } else {
            button.setActive(false);
        }
        button.draw(window);
    }
    return;
}
}
