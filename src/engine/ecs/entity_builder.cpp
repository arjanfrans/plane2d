#include "entity_builder.h"
#include "player.h"
#include "components/view_component.h"

namespace pl {

EntityBuilder::EntityBuilder(std::shared_ptr<Engine> engine) : engine{engine} {
}

Player EntityBuilder::player() {
    Player player;
    ViewComponent view;
    view.setTexture(this->engine->resources.texture("smiley.png"));
    player.setViewComponent(view);
    return player;
}
}
