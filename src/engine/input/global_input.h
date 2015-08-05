#ifndef GLOBAL_INPUT_H
#define GLOBAL_INPUT_H

#include <SFML/Graphics.hpp>
#include "input.h"
#include "../engine.h"

namespace pl {

class GlobalInput : public Input {

public:
    GlobalInput(std::shared_ptr<Engine> engine);
    bool update(sf::Event event);

private:
    void closeWindow();
    bool keyInput(sf::Keyboard::Key code);
    void onResize(sf::Event event);
};
}
#endif
