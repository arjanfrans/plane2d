#include "entity_builder.h"
#include "components/input/player_input.h"
#include "components/view/player_view.h"
#include "../utils/logger.h"

namespace pl {

EntityBuilder::EntityBuilder(std::shared_ptr<Engine> engine) : engine{engine} {
}

std::unique_ptr<Player> EntityBuilder::player() {
    std::unique_ptr<Player> player{new Player()};
    PlayerInput input{*player.get()};
    PlayerView view{*player.get()};

    view.setTexture(this->engine->resources.texture("smiley.png"));
    player->setViewComponent(view);
    player->setInputComponent(input);
    LOG(INFO) << "Player created.";
    return player;
}
}
