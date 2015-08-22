#pragma once

#include <memory>
#include <vector>
#include <map>

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
    WorldState(std::shared_ptr<Engine> engine, std::shared_ptr<EntityContainer> entityContainer);
    void setInputs(std::vector<WorldInput> inputs);
    void setViews(std::map<std::string, WorldView> view);
    WorldView& getView(std::string name);
    void update(const float dt);
    void updateInput(sf::Event event);
    void resizeWindow(float width, float height);
    std::shared_ptr<EntityContainer> entityContainer;

private:
    std::vector<WorldInput> inputs;
    std::map<std::string, WorldView> views;
    void updateViews();
};
}

