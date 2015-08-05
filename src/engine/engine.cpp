#include <memory>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "engine.h"
#include "config.h"
#include "states/state.h"

#include "utils/logger.h"

namespace pl {
Engine::Engine(std::shared_ptr<Config> config) : config{config} {
    auto gameConfig = this->config->get("game");
    this->fullscreen = this->config->get("game")["fullscreen"].as<bool>();
    auto width = gameConfig["width"].as<unsigned int>();
    auto height = gameConfig["height"].as<unsigned int>();
    changeWindow(width, height, this->fullscreen);
}

void Engine::changeFullscreen() {
    auto gameConfig = this->config->get("game");
    auto width = gameConfig["width"].as<unsigned int>();
    auto height = gameConfig["height"].as<unsigned int>();

    this->fullscreen = !this->fullscreen;
    changeWindow(width, height, this->fullscreen);
    return;
}

void Engine::changeWindow(unsigned int width, unsigned int height, bool fullscreen) {
    auto gameConfig = this->config->get("game");
    auto title = gameConfig["title"].as<std::string>();
    auto desktopMode = sf::VideoMode::getDesktopMode();

    sf::VideoMode videoMode{width, height};
    if (width > desktopMode.width || height > desktopMode.height) {
        videoMode.width = 800;
        videoMode.height = 600;
        LOG(WARNING) << "VideoMode too large for screen, falling back to default.";
    }

    if (fullscreen && !videoMode.isValid()) {
        videoMode = desktopMode;
        LOG(WARNING) << "Invalid fullscreen VideoMode, falling back to desktop mode.";
    }

    if (fullscreen) {
        LOG(INFO) << "Changing to fullscreen.";
        this->window.create(videoMode, title, sf::Style::Fullscreen);
    } else {
        LOG(INFO) << "Changing to window mode.";
        this->window.create(videoMode, title, sf::Style::Default);
    }
    this->window.setFramerateLimit(60);
    return;
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
