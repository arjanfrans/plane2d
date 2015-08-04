#include <string>
#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

#include "menu_state.h"
#include "menu_view.h"
#include "../../ui/button.h"

#include "../../utils/logger.h"

const int VIRTUAL_WIDTH = 800;
const int VIRTUAL_HEIGHT = 600;
namespace pl {

MenuView::MenuView(std::shared_ptr<MenuState> state) : state{state} {
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
    auto& font = this->state->engine->resources.font(fontName);

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
    float VIRTUAL_RATIO = VIRTUAL_WIDTH / VIRTUAL_HEIGHT;
    float ratio = width / height;
    float scale = 1;
    sf::Vector2f crop{0, 0};

    if (ratio > VIRTUAL_RATIO) {
        scale = height / VIRTUAL_HEIGHT;
        crop.x = ((width - (VIRTUAL_WIDTH * scale)) / 2) / width;
    } else if (ratio < VIRTUAL_RATIO) {
        scale = width / VIRTUAL_WIDTH;
        crop.y = ((height - (VIRTUAL_HEIGHT * scale)) / 2) / height;
    } else {
        scale = width / VIRTUAL_WIDTH;
    }

    auto w = (VIRTUAL_WIDTH * scale) / width;
    auto h = (VIRTUAL_HEIGHT * scale) / height;
    this->fixedView.setViewport(sf::FloatRect(crop.x, crop.y, w, h));
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
