#pragma once

#include <memory>
#include <vector>

#include "../state.h"
#include "../../engine.h"
#include "../../ecs/entity.h"

namespace pl {

class WorldView;
class WorldInput;

class WorldState : public State {

public:
    WorldState(std::shared_ptr<Engine> engine);
    void setInputs(std::vector<WorldInput> inputs);
    void setViews(std::vector<WorldView> view);
    void update(const float dt);
    void updateInput(sf::Event event);
    void resizeWindow(float width, float height);
    void addEntity(std::unique_ptr<Entity> entity);
    std::vector<std::unique_ptr<Entity>> entities;

private:
    std::vector<WorldInput> inputs;
    std::vector<WorldView> views;
    void updateViews();
};
}

