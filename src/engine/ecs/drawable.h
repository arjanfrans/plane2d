#pragma once

#include <SFML/Graphics.hpp>

#include "components/view_component.h"
namespace pl {

class Drawable {

public:
    void setViewComponent(ViewComponent view);
    ViewComponent getViewComponent();
    virtual void draw();

private:
    ViewComponent view;
};
}
