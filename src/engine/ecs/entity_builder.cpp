#include "entity_builder.h"
#include "player.h"
#include "components/input/player_input.h"
#include "components/view/player_view.h"
#include "../utils/logger.h"

namespace pl {

EntityBuilder::EntityBuilder(std::shared_ptr<Engine> engine) : engine{engine} {
}

std::shared_ptr<Player> EntityBuilder::player() {
    auto player = std::make_shared<Player>();
    // PlayerView view{player.get()};

    // view.setTexture(this->engine->resources.texture("smiley.png"));
    // player->setViewComponent(view);
    auto input = std::unique_ptr<InputComponent>{new PlayerInput(player)};
    player->setInputComponent(std::move(input));
    LOG(INFO) << "Player created.";
    return player;
}
}
