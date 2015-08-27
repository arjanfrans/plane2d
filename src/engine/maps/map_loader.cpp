#include <memory>
#include "map_loader.h"

#include "../utils/logger.h"

namespace pl {

MapLoader::MapLoader() {

}

Tmx::Map MapLoader::loadMap(std::string name) {
    auto map = std::unique_ptr<Tmx::Map>{new Tmx::Map()};
    map->ParseFile("data/maps/platformer.tmx");
    if(map->HasError()) {
        LOG(ERROR) << map->GetErrorCode();
        LOG(ERROR) << map->GetErrorText();
    }
}

}
