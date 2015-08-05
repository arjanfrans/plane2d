#include "menu_view.h"

#include "../../utils/logger.h"

namespace pl {

MenuView::MenuView(std::shared_ptr<MenuState> state, float width, float height)
    : View{width, height}, state{state} {
    this->fixedView = this->state->engine->window.getView();
    createBackground();
    createButtons();
}

void MenuView::createBackground() {
    auto config = this->state->config->get("menu");
    auto size = this->fixedView.getSize();
    auto textureName = config["background"].as<std::string>();
    this->background.setTexture(this->state->engine->resources.texture(textureName));
    this->background.setPosition(0, 0);
    return;
}

void MenuView::createButtons() {
    auto size = this->fixedView.getSize();
    auto itemCount = this->state->items.size();
    auto itemHeight = size.y / itemCount;
    auto fontName = this->state->config->get("menu")["font"]["name"].as<std::string>();
    auto &font = this->state->engine->resources.font(fontName);

    for (int i = 0; i < this->state->items.size(); ++i) {
        auto &itemKey = this->state->itemKeys.at(i);
        auto &item = this->state->items.at(i);
        float x = size.x / 2;
        float y = (itemHeight / 2) * i;
        LOG(INFO) << y;
        sf::Vector2f position{x, y};

        auto button = std::make_shared<ui::Button>(item, position, itemKey, font, sf::Color::Green,
                                                   sf::Color::Cyan, 24);
        this->buttons.push_back(button);
    }
    return;
}

void MenuView::resize(float width, float height) {
    this->fixedView.setViewport(this->virtualResolutionViewport(width, height));
    return;
}

void MenuView::draw(sf::RenderWindow &window) {
    window.setView(this->fixedView);
    window.draw(this->background);
    for (int i = 0; i < this->buttons.size(); ++i) {
        auto &button = this->buttons.at(i);
        if (i == this->state->selectedItemIndex) {
            button->setActive(true);
        } else {
            button->setActive(false);
        }
        window.draw(button->getDrawable());
    }
    return;
}
}
