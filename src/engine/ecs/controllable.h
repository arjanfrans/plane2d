#pragma once

#include <SFML/Graphics.hpp>

#include "components/input_component.h"

namespace pl {

class Controllable {
public:
    void setInputComponent(InputComponent view);
    InputComponent getInputComponent();
    void updateInput(sf::Event event);

private:
    InputComponent view;
};
}
