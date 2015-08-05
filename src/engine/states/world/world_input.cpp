#include <memory>

#include <SFML/Graphics.hpp>

#include "world_input.h"
#include "../../input/input.h"

#include "../../utils/logger.h"

namespace pl {

WorldInput::WorldInput(std::shared_ptr<WorldState> state) : Input(state->engine) {
}

bool WorldInput::update(sf::Event event) {
    switch (event.type) {
        default:
            return false;
    }
}

// void WorldInput::onResize(sf::Event event) {
//     this->state->resizeViews(event.size.width, event.size.height);
//     return;
// }
}
