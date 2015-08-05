#ifndef INPUT_INPUT_H
#define INPUT_INPUT_H

#include <SFML/Graphics.hpp>
#include "../engine.h"

namespace pl {

class Input {

public:
    Input(std::shared_ptr<Engine> engine);
    void update(sf::Event event);

private:
    std::shared_ptr<Engine> engine;
    virtual void keyInput(sf::Event) = 0;
    virtual void mouseClick(sf::Event) = 0;
    virtual void mouseMovement(sf::Event) = 0;
    virtual void closeWindow(sf::Event event);
    virtual void onResize(sf::Event event) = 0;
};
}

#endif
