#pragma once

#include <SFML/Graphics.hpp>


namespace pl {
class ViewComponent;

class Drawable {

public:
    void setViewComponent(ViewComponent view);
    const ViewComponent &getViewComponent();

private:
    ViewComponent view;
};
}
