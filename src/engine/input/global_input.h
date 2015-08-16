#pragma once

#include <SFML/Graphics.hpp>

#include "../engine.h"
#include "input.h"

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
