#include <vector>
#include <memory>
#include <map>

#include "input/menu_input.h"
#include "game.h"
#include "game_state_menu.h"
#include "view/menu/button.h"

#include "utils/logger.h"

GameStateMenu::GameStateMenu(std::shared_ptr<Game> game) : selectedItemIndex{0} {
    this->game = game;

    // Parallel arrays
    this->itemKeys = {"start", "options", "exit"};
    this->items = {"Start", "Options", "Exit"};
}

void GameStateMenu::setInputs(std::vector<input::MenuInput> inputs) {
    this->inputs = std::move(inputs);
    return;
}

void GameStateMenu::setViews(std::vector<view::MenuView> views) {
    this->views = std::move(views);
    return;
}

void GameStateMenu::moveUp() {
    if (this->selectedItemIndex > 0) {
        this->selectedItemIndex = this->selectedItemIndex - 1;
        return;
    }
    LOG(INFO) << "Can not move up.";
    return;
}

void GameStateMenu::moveDown() {
    if (this->selectedItemIndex < this->items.size() - 1) {
        this->selectedItemIndex = this->selectedItemIndex + 1;
        return;
    }
    LOG(INFO) << "Can not move down.";
    return;
}

void GameStateMenu::setSelectedItem(std::string key) {
    this->selectedItemIndex = std::find(this->itemKeys.begin(), this->itemKeys.end(), key) - this->itemKeys.begin();
}

void GameStateMenu::select() {
    auto key = this->itemKeys.at(this->selectedItemIndex);
    if (key == "start") {

    } else if (key == "options") {

    } else if (key == "exit") {
        this->game->window.close();
        LOG(INFO) << "Closing window.";
    } else {
        LOG(INFO) << "selectedItemIndex does not do anything.";
    }
    return;
    return;
}

void GameStateMenu::update(const float dt) {
    updateInputs();
    updateViews();
    return;
}

std::vector<std::shared_ptr<view::menu::Button>> GameStateMenu::getButtons() {
    std::vector<std::shared_ptr<view::menu::Button>> buttons;
    for (auto &view : this->views) {
        for (auto &button : view.buttons) {
            buttons.push_back(button);
        }
    }
    return buttons;
}

void GameStateMenu::updateInputs() {
    if (this->inputs.size() > 0) {
        sf::Event event;

        while (this->game->window.pollEvent(event)) {
            for (auto &input : this->inputs) {
                input.update(event);
            }
        }
    }
    return;
}

void GameStateMenu::updateViews() {
    if (this->views.size() > 0) {
        for (auto &view : this->views) {
            view.draw(this->game->window);
        }
    }
    return;
}
