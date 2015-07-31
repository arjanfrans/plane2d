#include <memory>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "game_state.h"

Game::Game() 
: window{new sf::RenderWindow(sf::VideoMode(800, 600), "brecourt")}
{
    this->window->setFramerateLimit(60);
}

void Game::loop() {
    sf::Clock clock;

    while(this->window->isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if(peekState() != nullptr) {
            peekState()->update(dt);
            this->window->clear(sf::Color::Black);
            // TODO: update views
            this->window->display();
        }
    }
    return;
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
