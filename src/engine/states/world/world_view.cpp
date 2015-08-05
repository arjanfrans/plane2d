#include "world_view.h"

namespace pl {

WorldView::WorldView(std::shared_ptr<WorldState> state) : state{state} {
    this->fixedView = this->state->engine->window.getView();
    createBackground();
}


void WorldView::createBackground() {
    auto config = this->state->config->get("game");
    auto size = this->fixedView.getSize();
    auto textureName = config["background"].as<std::string>();
    this->background.setTexture(this->state->engine->resources.texture(textureName));
    this->background.setPosition(0, 0);
    return;
}


void WorldView::draw(sf::RenderWindow &window) {
    window.setView(this->fixedView);
    window.draw(this->background);
}
}