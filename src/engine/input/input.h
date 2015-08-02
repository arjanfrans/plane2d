#ifndef INPUT_INPUT_H
#define INPUT_INPUT_H

#include <SFML/Graphics.hpp>

namespace pl {

class Input {

public:
    void update(sf::Event event);

private:
    virtual void keyInput(sf::Event) = 0;
    virtual void mouseClick(sf::Event) = 0;
    virtual void mouseMovement(sf::Event) = 0;
    virtual void closeWindow(sf::Event event) = 0;
};
}

#endif
