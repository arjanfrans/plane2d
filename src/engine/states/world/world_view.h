#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include <memory>

#include <SFML/Graphics.hpp>

#include "world_state.h"

namespace pl {
class WorldState;

class WorldView {

public:
    WorldView(std::shared_ptr<WorldState> state);
    std::shared_ptr<WorldState> state;
    void resize(float width, float height);
    void draw(sf::RenderWindow &window);
    sf::View fixedView;
    sf::Sprite background;

private:
    void createBackground();
};
}
#endif
