#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../entity.h"

namespace pl {

class ViewComponent {

public:
    ViewComponent();
    ViewComponent(std::shared_ptr<Entity> entity);
    void setTexture(sf::Texture &texture);
    sf::Sprite sprite;
};
}
