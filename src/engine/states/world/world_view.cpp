#include "world_view.h"

namespace pl {

WorldView::WorldView(std::shared_ptr<WorldState> state, float width, float height)
    : View{width, height}, state{state}, cameraFollow{nullptr} {
    this->fixedView = this->state->engine->window.getView();
    this->dynamicView = this->state->engine->window.getView();
    createBackground();
}

void WorldView::resize(float width, float height) {
    this->fixedView.setViewport(this->virtualResolutionViewport(width, height));
    this->dynamicView.setViewport(this->virtualResolutionViewport(width, height));
    return;
}

void WorldView::createBackground() {
    auto config = this->state->config->get("game");
    auto size = this->fixedView.getSize();
    auto textureName = config["background"].as<std::string>();
    this->background.setTexture(this->state->engine->resources.texture(textureName));
    this->background.setPosition(0, 0);
    return;
}

void WorldView::setCameraFollow(std::shared_ptr<Entity> entity) {
    this->cameraFollow = entity;
}

void WorldView::updateCamera() {
    if (this->cameraFollow != nullptr) {
        this->dynamicView.setCenter(this->cameraFollow->getPosition());
    }
}

void WorldView::draw(sf::RenderWindow &window) {
    // Background
    window.setView(this->fixedView);
    window.draw(this->background);

    // Foreground
    updateCamera();
    window.setView(this->dynamicView);
}
}
