#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../entity.h"

namespace pl {

class InputComponent {

public:
    InputComponent();
    InputComponent(std::shared_ptr<Entity> entity);
    virtual bool checkInput(sf::Event input) = 0;
};
}
