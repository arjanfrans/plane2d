#include "drawable.h"
#include "../utils/logger.h"

namespace pl {

Drawable::Drawable() {
}

void Drawable::setViewComponent(std::unique_ptr<ViewComponent> view) {
    this->view = std::move(view);
}

const ViewComponent &Drawable::getViewComponent() {
    return *this->view.get();
}

void Drawable::updateView(sf::RenderWindow &window) {
    auto &view = getViewComponent();
    window.draw(view.sprite);
}
}
