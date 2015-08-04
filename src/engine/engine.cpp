#include <memory>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "engine.h"
#include "states/state.h"

#include "utils/logger.h"

namespace pl {
Engine::Engine(std::shared_ptr<Config> config) : config{config}, windowScale{sf::Vector2f(0, 0)} {
    auto gameConfig = config->get("game");
    auto title = gameConfig["title"].as<std::string>();
    bool fullscreen = gameConfig["fullscreen"].as<bool>();
    auto width = gameConfig["width"].as<unsigned int>();
    auto height = gameConfig["height"].as<unsigned int>();
    sf::VideoMode videoMode{width, height};
    auto desktopMode = sf::VideoMode::getDesktopMode();
    if(width > desktopMode.width || height > desktopMode.height) {
        videoMode.width = 800;
        videoMode.height = 600;
        LOG(WARNING) << "VideoMode too large for screen, falling back to default.";
    }

    if (fullscreen && !videoMode.isValid()) {
        videoMode = desktopMode;
        LOG(WARNING) << "Invalid fullscreen VideoMode, falling back to desktop mode.";
    }

    if (fullscreen) {
        this->window.create(videoMode, title, sf::Style::Fullscreen);
    } else {
        this->window.create(videoMode, title);
    }
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
