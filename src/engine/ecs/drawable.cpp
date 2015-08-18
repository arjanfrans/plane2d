#include "drawable.h"

namespace pl {

Drawable::Drawable() {}

void Drawable::setViewComponent(ViewComponent view) {
    this->view = view;
}
ViewComponent &Drawable::getViewComponent() {
    return this->view;
}

void Drawable::updateView(sf::RenderWindow &window) {
    auto &view = getViewComponent();
    window.draw(view.sprite);
}
}
