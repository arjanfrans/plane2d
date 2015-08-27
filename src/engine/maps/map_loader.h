#include <string>
#include <tmxparser/Tmx.h>

namespace pl {

class MapLoader {

public:
    MapLoader();
    Tmx::Map loadMap(std::string name);
};
}
