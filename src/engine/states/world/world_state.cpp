#include <memory>
#include <vector>

#include "../../engine.h"
#include "world_state.h"
#include "world_view.h"
#include "world_input.h"
namespace pl {

WorldState::WorldState(std::shared_ptr<Engine> engine) : State(engine) {
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
}
