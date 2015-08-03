#include <memory>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "engine.h"
#include "states/state.h"

#include "utils/logger.h"

namespace pl {
Engine::Engine(std::shared_ptr<Config> config) : config{config} {
    auto title = this->config->get("game")["title"].as<std::string>();
    this->window.create(sf::VideoMode(800, 600), title);
    this->window.setFramerateLimit(60);
}

void Engine::loop() {
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

void Engine::pushState(std::shared_ptr<State> state) {
    states.push(state);
    return;
}

void Engine::popState() {
    states.pop();
    return;
}

void Engine::changeState(std::shared_ptr<State> state) {
    if (!this->states.empty()) {
        popState();
    }
    pushState(move(state));
    return;
}

std::shared_ptr<State> Engine::peekState() {
    if (this->states.empty()) {
        return nullptr;
    }
    return this->states.top();
}
}
