#include "view_component.h"

namespace pl {

ViewComponent::ViewComponent() {
}

ViewComponent::ViewComponent(std::shared_ptr<Entity> entity) {
}

void ViewComponent::setTexture(sf::Texture &texture) {
    this->sprite.setTexture(texture);
}
}
