#include <string>
#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

#include "menu_state.h"
#include "menu_view.h"
#include "../../ui/button.h"

#include "../../utils/logger.h"

namespace pl {

MenuView::MenuView(std::shared_ptr<MenuState> state, std::string fontName)
    : font{std::make_shared<sf::Font>()} {
    this->state = state;
    if (!font->loadFromFile("data/fonts/" + fontName)) {
        this->state->stateManager->window.close();
        LOG(ERROR) << "Unable to load font.";
        exit(EXIT_FAILURE);
    }
    createButtons();
}

void MenuView::createButtons() {
    auto &window = this->state->stateManager->window;
    sf::Vector2u size{window.getSize()};
    auto itemCount = this->state->items.size();
    auto itemHeight = size.y / itemCount;

    for (int i = 0; i < this->state->items.size(); ++i) {
        auto &itemKey = this->state->itemKeys.at(i);
        auto &item = this->state->items.at(i);
        float x = size.x / 2;
        float y = (itemHeight / 2) * i;
        sf::Vector2f position{x, y};

        auto button = std::make_shared<ui::Button>(item, position, itemKey, this->font, sf::Color::Green,
                                                   sf::Color::Cyan, 24);
        this->buttons.push_back(button);
    }
    return;
}

void MenuView::draw(sf::RenderWindow &window) {
    for (int i = 0; i < this->buttons.size(); ++i) {
        auto &button = this->buttons.at(i);
        if (i == this->state->selectedItemIndex) {
            button->setActive(true);
        } else {
            button->setActive(false);
        }
        button->draw(window);
    }
    return;
}
}
