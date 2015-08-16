#pragma once

#include <SFML/Graphics.hpp>

#include "components/input_component.h"

namespace pl {

class Controllable {

public:
    void setInputComponent(InputComponent inputComponent);
    const InputComponent &getInputComponent();
    bool updateInput(sf::Event event);

private:
    InputComponent inputComponent;
};
}
