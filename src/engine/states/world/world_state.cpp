#include "world_state.h"
#include "world_view.h"
#include "world_input.h"
#include "../../utils/logger.h"

namespace pl {

WorldState::WorldState(std::shared_ptr<Engine> engine, std::shared_ptr<EntityContainer> entityContainer)
    : State{engine}, entityContainer{entityContainer} {
}

void WorldState::update(const float dt) {
    updateViews();
    this->entityContainer->update(dt);

    return;
}
void WorldState::setViews(std::vector<WorldView> views) {
    this->views = std::move(views);
    return;
}
void WorldState::setInputs(std::vector<WorldInput> inputs) {
    this->inputs = std::move(inputs);
    return;
}

void WorldState::resizeWindow(float width, float height) {
    for (auto &view : this->views) {
        view.resize(width, height);
    }
    return;
}

void WorldState::updateViews() {
    if (this->views.size() > 0) {
        for (auto &view : this->views) {
            view.draw(this->engine->window);
        }
    }
    return;
}

void WorldState::updateInput(sf::Event event) {
    for (auto &input : this->inputs) {
        input.update(event);
    }
    this->entityContainer->updateControllables(event);

    return;
}
}
