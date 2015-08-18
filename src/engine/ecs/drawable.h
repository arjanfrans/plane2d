#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "components/view_component.h"

namespace pl {

class Drawable {

public:
    Drawable();
    void setViewComponent(ViewComponent view);
    ViewComponent &getViewComponent();
    void updateView(sf::RenderWindow& window);

private:
    ViewComponent view;
};
}
