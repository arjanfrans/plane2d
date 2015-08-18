#include "view_component.h"

namespace pl {

void ViewComponent::setTexture(sf::Texture &texture) {
    this->sprite.setTexture(texture);
}
}

