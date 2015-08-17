#include "world_state.h"
#include "world_view.h"
#include "world_input.h"
#include "../../ecs/controllable.h"

namespace pl {

WorldState::WorldState(std::shared_ptr<Engine> engine) : State{engine} {
}

void WorldState::update(const float dt) {
    updateViews();
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
    return;
}

void WorldState::addEntity(std::unique_ptr<Entity> entity) {
    if(dynamic_cast<Controllable*>(entity.get()) {

    }   
    this->entities.push_back(std::move(entity));
}
}
