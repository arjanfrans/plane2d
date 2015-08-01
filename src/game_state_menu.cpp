#include <vector>
#include <memory>
#include <map>

#include "input/menu_input.h"
#include "game.h"
#include "game_state_menu.h"
#include "view/mouse_listener.h"

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

void GameStateMenu::selectByKey(std::string key) {
    if (key == "start") {

    } else if (key == "options") {

    } else if (key == "exit") {
        this->game->window.close();
        LOG(INFO) << "Closing window.";
    } else {
        LOG(INFO) << "selectedItemIndex does not do anything.";
    }
    return;
}

void GameStateMenu::select() {
    selectByKey(this->itemKeys.at(this->selectedItemIndex));
    return;
}

void GameStateMenu::update(const float dt) {
    updateInputs();
    updateViews();
    return;
}

// std::vector<view::MouseListener &> GameStateMenu::getMouseListeners() {
//     std::vector<view::MouseListener &> listeners;
//     for (auto &view : this->views) {
//         for (auto &listener : view.mouseListeners) {
//             listeners.insert(listener);
//         }
//     }
//     return listeners;
// }

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
