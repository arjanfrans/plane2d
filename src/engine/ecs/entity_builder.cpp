#include "entity_builder.h"
#include "player.h"
#include "components/input/player_input.h"
#include "components/view/player_view.h"

namespace pl {

EntityBuilder::EntityBuilder(std::shared_ptr<Engine> engine) : engine{engine} {
}

std::unique_ptr<Player> EntityBuilder::player() {
    auto player = std::unique_ptr<Player>{new Player()};
    // PlayerView view{player.get()};

    // view.setTexture(this->engine->resources.texture("smiley.png"));
    // player->setViewComponent(view);
    player->setInputComponent(std::unique_ptr<PlayerInput>{player});
    return player;
}
}
