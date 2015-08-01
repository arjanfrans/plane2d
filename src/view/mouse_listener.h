#ifndef VIEW_MOUSE_LISTENER_H
#define VIEW_MOUSE_LISTENER_H

#include <SFML/Graphics.hpp>

namespace view {

class MouseListener {

public:
    sf::Rect<float> bounds;
    bool overlaps(sf::Vector2f position);
};
}
#endif
