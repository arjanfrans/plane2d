#pragma once

#include <memory>
#include <stack>

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_manager.h"


namespace pl {

class GlobalInput;

class State;
class EntityBuilder;
class StateBuilder;

class Engine {

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
    void setStateBuilder(std::unique_ptr<StateBuilder> stateBuilder);
    void setEntityBuilder(std::unique_ptr<EntityBuilder> entityBuilder);
    const StateBuilder &getStateBuilder();
    const EntityBuilder &getEntityBuilder();
    void setGlobalInput(std::unique_ptr<GlobalInput> input);

private:
    std::unique_ptr<GlobalInput> globalInput;
    void eventLoop(std::shared_ptr<State> state);
    std::unique_ptr<StateBuilder> stateBuilder;
    std::unique_ptr<EntityBuilder> entityBuilder;
};
}
