#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include <stack>

#include <SFML/Graphics.hpp>

#include "config.h"
#include "states/state.h"
#include "resource_manager.h"
#include "input/global_input.h"
#include "states/state_builder.h"
#include "ecs/entity_builder.h"

namespace pl {

class GlobalInput;

class State;

class Engine : public std::enable_shared_from_this<Engine> {

public:
    Engine(std::shared_ptr<Config> config);
    void loop();
    std::shared_ptr<Config> config;
    std::stack<std::shared_ptr<State>> states;
    void pushState(std::shared_ptr<State> state);
    void popState();
    void changeState(std::shared_ptr<State> state);
    std::shared_ptr<State> peekState();
    sf::RenderWindow window;
    bool fullscreen;
    void changeFullscreen();
    void changeWindow(unsigned int width, unsigned int height, bool fullscreen);
    ResourceManager resources;
    StateBuilder stateBuilder;
    EntityBuilder entityBuilder;
    void setGlobalInput(std::unique_ptr<GlobalInput> input);

private:
    std::unique_ptr<GlobalInput> globalInput;
    void eventLoop(std::shared_ptr<State> state);
};
}

#endif
