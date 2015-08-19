#include "controllable.h"
#include "../utils/logger.h"

namespace pl {

Controllable::Controllable() {}


bool Controllable::updateInput(sf::Event event) {
    return this->inputComponent->checkInput(event);
}

void Controllable::setInputComponent(std::unique_ptr<InputComponent> inputComponent) {
    this->inputComponent = std::move(inputComponent);
}

const InputComponent &Controllable::getInputComponent() {
    return *this->inputComponent.get();
}
}
