#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "world_state.h"
#include "../view.h"
#include "../../ecs/entity.h"

namespace pl {
class WorldState;

class WorldView : public View {

public:
    WorldView(std::shared_ptr<WorldState> state, float width, float height);
    std::shared_ptr<WorldState> state;
    void draw(sf::RenderWindow &window);
    sf::View fixedView;
    sf::View dynamicView;
    sf::Sprite background;
    void setCameraFollow(std::shared_ptr<Entity> entity);
    std::shared_ptr<Entity> cameraFollow;
    void updateCamera();
    void resize(float width, float height);

private:
    void createBackground();
};
}
