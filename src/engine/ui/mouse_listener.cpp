
#include <SFML/Graphics.hpp>
#include "mouse_listener.h"
#include "../utils/logger.h"

namespace pl {
namespace ui {

bool MouseListener::overlaps(sf::Vector2f position) {
    return getBounds().contains(position);
}
}
}
