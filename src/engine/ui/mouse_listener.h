#ifndef VIEW_MOUSE_LISTENER_H
#define VIEW_MOUSE_LISTENER_H

#include <SFML/Graphics.hpp>

namespace pl {
namespace ui {

class MouseListener {

public:
    sf::Rect<float> bounds;
    bool overlaps(sf::Vector2f position);
};
}
}
#endif
