#ifndef VIEW_MOUSE_LISTENER_H
#define VIEW_MOUSE_LISTENER_H

#include <SFML/Graphics.hpp>

namespace pl {
namespace ui {

class MouseListener {

public:
    virtual sf::FloatRect getBounds() = 0;
    bool overlaps(sf::Vector2f position);
};
}
}
#endif
