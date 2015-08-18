#pragma once

#include <memory>
#include <vector>

#include "../state.h"
#include "../../engine.h"
#include "../../ecs/entity.h"
#include "../../ecs/controllable.h"
#include "../../ecs/entity_container.h"

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
    void setEntityContainer(std::unique_ptr<EntityContainer> entityContainer);
    std::vector<Controllable*> controllables;
    std::unique_ptr<EntityContainer> entityContainer;

private:
    std::vector<WorldInput> inputs;
    std::vector<WorldView> views;
    void updateViews();
};
}

