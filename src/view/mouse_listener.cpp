
#include <SFML/Graphics.hpp>
#include "mouse_listener.h"

namespace view {

bool MouseListener::overlaps(sf::Vector2f position) {
    return this->bounds.contains(position);
}
}
