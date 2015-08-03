#include <memory>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "state_manager.h"
#include "state.h"

#include "../utils/logger.h"

namespace pl {
StateManager::StateManager(std::shared_ptr<Config> config) : config{config} {
    auto title = this->config->get("game")["title"].as<std::string>();
    this->window.create(sf::VideoMode(800, 600), title);
    this->window.setFramerateLimit(60);
}

void StateManager::loop() {
    LOG(INFO) << "Start game loop.";
    sf::Clock clock;

    while (this->window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();
        if (peekState() != nullptr) {
            this->window.clear(sf::Color::Black);
            peekState()->update(dt);
            this->window.display();
        }
    }
    return;
}

void StateManager::pushState(std::shared_ptr<State> state) {
    states.push(state);
    return;
}

void StateManager::popState() {
    states.pop();
    return;
}

void StateManager::changeState(std::shared_ptr<State> state) {
    if (!this->states.empty()) {
        popState();
    }
    pushState(move(state));
    return;
}

std::shared_ptr<State> StateManager::peekState() {
    if (this->states.empty()) {
        return nullptr;
    }
    return this->states.top();
}
}
