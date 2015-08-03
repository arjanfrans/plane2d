#include <vector>
#include <memory>
#include <map>

#include "menu_input.h"
#include "menu_state.h"

#include "../state_manager.h"
#include "../../ui/button.h"

#include "../../utils/logger.h"

namespace pl {

MenuState::MenuState(std::shared_ptr<StateManager> stateManager) : selectedItemIndex{0} {
    this->stateManager = stateManager;
    this->config = stateManager->config;

    // Parallel arrays
    this->itemKeys = {"start", "options", "exit"};
    this->items = {"Start", "Options", "Exit"};
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

void MenuState::select() {
    auto key = this->itemKeys.at(this->selectedItemIndex);
    if (key == "start") {

    } else if (key == "options") {

    } else if (key == "exit") {
        this->stateManager->window.close();
        LOG(INFO) << "Closing window.";
    } else {
        LOG(INFO) << "selectedItemIndex does not do anything.";
    }
    return;
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

        while (this->stateManager->window.pollEvent(event)) {
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
            view.draw(this->stateManager->window);
        }
    }
    return;
}
}

