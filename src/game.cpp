#include <memory>

#include "game.h"
#include "game_state.h"

Game::Game() {
}

void Game::init() {
}

void Game::loop() {

}

void Game::pushState(std::shared_ptr<GameState> state) {
    states.push(state);
    return;
}

void Game::popState() {
    states.pop();
    return;
}

void Game::changeState(std::shared_ptr<GameState> state) {
    if(!this->states.empty()) {
            popState();
        }
    pushState(move(state));
    return;
}

std::shared_ptr<GameState> Game::peekState() {
    if(this->states.empty()) {
            return nullptr;
        }
    return this->states.top();
}
