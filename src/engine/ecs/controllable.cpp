#include "controllable.h"

namespace pl {

Controllable::Controllable() {}


bool Controllable::updateInput(sf::Event event) {
    return this->inputComponent.checkInput(event);
}

void Controllable::setInputComponent(InputComponent inputComponent) {
    this->inputComponent = std::move(inputComponent);
}

const InputComponent &Controllable::getInputComponent() {
    return this->inputComponent;
}
}
