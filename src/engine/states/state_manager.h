#ifndef STATE_MANAGER_H_
#define STATE_MANAGER_H_

#include <memory>
#include <vector>
#include <stack>

#include <SFML/Graphics.hpp>

#include "state.h"

namespace pl {

class State;

class StateManager {

public:
    StateManager();
    void loop();
    std::stack<std::shared_ptr<State>> states;
    void pushState(std::shared_ptr<State> state);
    void popState();
    void changeState(std::shared_ptr<State> state);
    std::shared_ptr<State> peekState();
    sf::RenderWindow window;

private:
};
}

#endif
