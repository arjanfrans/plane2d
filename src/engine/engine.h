#ifndef STATE_MANAGER_H_
#define STATE_MANAGER_H_

#include <memory>
#include <vector>
#include <stack>

#include <SFML/Graphics.hpp>

#include "config.h"
#include "states/state.h"

namespace pl {

class State;

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
    sf::Vector2f windowScale;

private:
};
}

#endif
