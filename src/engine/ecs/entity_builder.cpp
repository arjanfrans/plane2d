#include "entity_builder.h"

namespace pl {

EntityBuilder::EntityBuilder(std::shared_ptr<Engine> engine) : engine{engine} {
}

std::unique_ptr<Player> EntityBuilder::player() {
    std::unique_ptr<Player> player{new Player()};
    ViewComponent view;
    view.setTexture(this->engine->resources.texture("smiley.png"));
    player->setViewComponent(view);
    return player;
}
}
