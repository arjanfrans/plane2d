#pragma once

#include <memory>

#include "player.h"
#include "../engine.h"

namespace pl {

class EntityBuilder {

public:
    EntityBuilder(std::shared_ptr<Engine> engine);
    std::unique_ptr<Player> player();

private:
    std::shared_ptr<Engine> engine;
};
}
