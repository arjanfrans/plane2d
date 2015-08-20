#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "components/view_component.h"

namespace pl {

class Drawable {

public:
    Drawable();
    void setViewComponent(std::unique_ptr<ViewComponent> view);
    const ViewComponent &getViewComponent();
    void updateView(sf::RenderWindow &window);

private:
    std::unique_ptr<ViewComponent> view;
};
}
