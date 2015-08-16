#pragma once

#include <memory>
#include <stack>
#include <string>
#include <map>

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
    std::map<std::string, std::shared_ptr<State>> states;
    void addState(std::string name, std::shared_ptr<State> state);
    void removeState(std::string name);
    void changeState(std::string name);
    std::shared_ptr<State> currentState;

    sf::RenderWindow window;
    bool fullscreen;
    void changeFullscreen();
    void changeWindow(unsigned int width, unsigned int height, bool fullscreen);
    ResourceManager resources;
    void setStateBuilder(std::shared_ptr<StateBuilder> stateBuilder);
    void setEntityBuilder(std::shared_ptr<EntityBuilder> entityBuilder);
    std::shared_ptr<StateBuilder> getStateBuilder();
    std::shared_ptr<EntityBuilder> getEntityBuilder();
    void setGlobalInput(std::unique_ptr<GlobalInput> input);

private:
    std::unique_ptr<GlobalInput> globalInput;
    void eventLoop(std::shared_ptr<State> state);
    std::shared_ptr<EntityBuilder> entityBuilder;
    std::shared_ptr<StateBuilder> stateBuilder;
};
}
