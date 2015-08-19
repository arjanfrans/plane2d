#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "components/input_component.h"

namespace pl {

class Controllable {

public:
    Controllable();
    void setInputComponent(std::unique_ptr<InputComponent> inputComponent);
    const InputComponent &getInputComponent();
    bool updateInput(sf::Event event);

private:
    std::unique_ptr<InputComponent> inputComponent;
};
}
