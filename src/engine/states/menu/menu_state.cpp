#include <vector>
#include <memory>
#include <map>

#include "menu_input.h"
#include "menu_state.h"
#include "menu_view.h"

#include "../state.h"
#include "../../engine.h"
#include "../../ui/button.h"
#include "../state_builder.h"

#include "../../utils/logger.h"

namespace pl {

MenuState::MenuState(std::shared_ptr<Engine> engine) : State(engine), selectedItemIndex{0} {
    // Parallel arrays
    this->itemKeys = {"start", "options", "exit"};
    this->items = {"Start", "Options", "Exit"};
}

void MenuState::resizeViews(float width, float height) {
    for (auto &view : this->views) {
        view.resize(width, height);
    }
    return;
}
void MenuState::setInputs(std::vector<MenuInput> inputs) {
    this->inputs = std::move(inputs);
    return;
}

void MenuState::setViews(std::vector<MenuView> views) {
    this->views = std::move(views);
    return;
}

void MenuState::moveUp() {
    if (this->selectedItemIndex > 0) {
        this->selectedItemIndex = this->selectedItemIndex - 1;
        return;
    }
    LOG(INFO) << "Can not move up.";
    return;
}

void MenuState::moveDown() {
    if (this->selectedItemIndex < this->items.size() - 1) {
        this->selectedItemIndex = this->selectedItemIndex + 1;
        return;
    }
    LOG(INFO) << "Can not move down.";
    return;
}

void MenuState::setSelectedItem(std::string key) {
    this->selectedItemIndex =
        std::find(this->itemKeys.begin(), this->itemKeys.end(), key) - this->itemKeys.begin();
}

void MenuState::onStart() {
    this->engine->pushState(StateBuilder::worldState(this->engine));
    return;
};

void MenuState::onOptions() {
    LOG(WARNING) << "Not implemented.";
    return;
}

void MenuState::select() {
    auto key = this->itemKeys.at(this->selectedItemIndex);
    if (key == "start") {
        onStart();
    } else if (key == "options") {
        onOptions();
    } else if (key == "exit") {
        onExit();
        LOG(INFO) << "Closing window.";
    } else {
        LOG(INFO) << "selectedItemIndex does not do anything.";
    }
    return;
}

void MenuState::update(const float dt) {
    updateInputs();
    updateViews();
    return;
}

std::vector<std::shared_ptr<ui::Button>> MenuState::getButtons() {
    std::vector<std::shared_ptr<ui::Button>> buttons;
    for (auto &view : this->views) {
        for (auto &button : view.buttons) {
            buttons.push_back(button);
        }
    }
    return buttons;
}

void MenuState::updateInputs() {
    if (this->inputs.size() > 0) {
        sf::Event event;

        while (this->engine->window.pollEvent(event)) {
            for (auto &input : this->inputs) {
                input.update(event);
            }
        }
    }
    return;
}

void MenuState::updateViews() {
    if (this->views.size() > 0) {
        for (auto &view : this->views) {
            view.draw(this->engine->window);
        }
    }
    return;
}
}

