#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "world_state.h"
#include "../view.h"

namespace pl {
class WorldState;

class WorldView : public View {

public:
    WorldView(std::shared_ptr<WorldState> state, float width, float height);
    std::shared_ptr<WorldState> state;
    void draw(sf::RenderWindow &window);
    sf::View fixedView;
    sf::Sprite background;
    void resize(float width, float height);

private:
    void createBackground();
};
}
