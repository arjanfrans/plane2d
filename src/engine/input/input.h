#ifndef INPUT_INPUT_H
#define INPUT_INPUT_H

#include <SFML/Graphics.hpp>
#include "../engine.h"

namespace pl {

class Engine;
class Input {

public:
    Input(std::shared_ptr<Engine> engine);
    virtual bool update(sf::Event event) = 0;
    std::shared_ptr<Engine> engine;

private:
};
}

#endif
