#include "engine.h"
#include "utils/logger.h"
#include "states/state_builder.h"
#include "input/global_input.h"
#include "ecs/entity_builder.h"
#include "states/state_builder.h"
#include "states/state.h"

namespace pl {
Engine::Engine(std::shared_ptr<Config> config) : config{config}, globalInput{nullptr}, entityBuilder{nullptr}, stateBuilder{nullptr} {
    auto gameConfig = this->config->get("game");
    this->fullscreen = this->config->get("game")["fullscreen"].as<bool>();
    auto width = gameConfig["width"].as<unsigned int>();
    auto height = gameConfig["height"].as<unsigned int>();
    changeWindow(width, height, this->fullscreen);
}

void Engine::setGlobalInput(std::unique_ptr<GlobalInput> input) {
    this->globalInput = std::move(input);
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
    if (this->globalInput == nullptr) {
        LOG(FATAL) << "No global input.";
    }
    LOG(INFO) << "Start game loop.";
    sf::Clock clock;

    while (this->window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();
        eventLoop(peekState());
        if (peekState() != nullptr) {
            this->window.clear(sf::Color::Black);
            peekState()->update(dt);
            this->window.display();
        }
    }
    return;
}

void Engine::eventLoop(std::shared_ptr<State> state) {
    sf::Event event;
    while (this->window.pollEvent(event)) {
        // Do not update state input if there is a global input.
        if (!this->globalInput->update(event)) {
            if (state != nullptr) {
                state->updateInput(event);
            }
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

void Engine::setStateBuilder(std::unique_ptr<StateBuilder> builder) {
    this->stateBuilder = std::move(builder);
}

void Engine::setEntityBuilder(std::unique_ptr<EntityBuilder> builder) {
    this->entityBuilder = std::move(builder);
}

const StateBuilder& Engine::getStateBuilder() {
    return *this->stateBuilder;
}

const EntityBuilder& Engine::getEntityBuilder() {
    return *this->entityBuilder;
}
}
