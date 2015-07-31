#include <vector>
#include <memory>

#include "input/menu_input.h"
#include "game.h"
#include "game_state_menu.h"

GameStateMenu::GameStateMenu(std::shared_ptr<Game> game) {
    this->game = game;
}

void GameStateMenu::setInputs(std::vector<std::unique_ptr<input::MenuInput>> inputs) {
    this->inputs = std::move(inputs);
}

void GameStateMenu::update(const float dt) {
    updateInputs();
}

void GameStateMenu::updateInputs() {
    if(this->inputs.size() > 0) {
        sf::Event event;

        while(this->game->window->pollEvent(event)) {
            for(auto& input : this->inputs) {
                input->update(event);
            }
        }
    }

}
