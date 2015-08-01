#include <vector>
#include <memory>
#include <map>

#include "input/menu_input.h"
#include "game.h"
#include "game_state_menu.h"

#include "utils/logger.h"

GameStateMenu::GameStateMenu(std::shared_ptr<Game> game)
    : items{{"Start game"}, {"Options"}, {"Exit game"}}, selectedItemIndex{0} {
    this->game = game;
}

void GameStateMenu::setInputs(std::vector<input::MenuInput> inputs) {
    this->inputs = std::move(inputs);
    return;
}

void GameStateMenu::setViews(std::vector<view::MenuView> views) {
    this->views = std::move(views);
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

void GameStateMenu::moveUp() {
    if (this->selectedItemIndex > 0) {
        this->selectedItemIndex = this->selectedItemIndex - 1;
        return;
    }
    LOG(INFO) << "Can not move up.";
    return;
}

void GameStateMenu::select() {
    switch (this->selectedItemIndex) {
        case MenuItem::EXIT:
            this->game->window.close();
            LOG(INFO) << "Closing window.";
            break;
        default:
            LOG(INFO) << "selectedItemIndex does not do anything.";
            break;
    }
    return;
}

void GameStateMenu::update(const float dt) {
    updateInputs();
    updateViews();
    return;
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
