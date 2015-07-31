#include <vector>
#include <memory>
#include <map>

#include "input/menu_input.h"
#include "game.h"
#include "game_state_menu.h"

#include "utils/logger.h"

GameStateMenu::GameStateMenu(std::shared_ptr<Game> game)
: items{
    {MenuItem::START, "Start game"},
    {MenuItem::EXIT, "Exit game"}
}
{
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

void GameStateMenu::moveUp() {
    if(this->selectedItemIndex < this->items.size()) {
        this->selectedItemIndex = this->selectedItemIndex + 1;
        return;
    }
    LOG(INFO) << "Can not move up.";
    return;
}

void GameStateMenu::moveDown() {
    if(this->selectedItemIndex > 0) {
        this->selectedItemIndex = this->selectedItemIndex - 1;
        return;
    }
    LOG(INFO) << "Can not move down.";
    return;
}
void GameStateMenu::update(const float dt) {
    updateInputs();
    return;
}

void GameStateMenu::updateInputs() {
    if(this->inputs.size() > 0) {
        sf::Event event;

        while(this->game->window.pollEvent(event)) {
            for(auto& input : this->inputs) {
                input.update(event);
            }
        }
    }
    return;
}
