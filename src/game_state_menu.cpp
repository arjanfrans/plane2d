#include <vector>
#include <memory>

#include "input/input.h"
#include "input/menu/input_menu.h"
#include "game.h"
#include "game_state_menu.h"

GameStateMenu::GameStateMenu(std::shared_ptr<Game> game) {
    this->game = game;
    // this->inputs.push_back(std::unique_ptr<input::InputMenu>{new input::InputMenu()});
}

void GameStateMenu::update(const float dt) {
    // for(auto& input : this->inputs) {
    //     input->update(dt);
    // }
}
