#pragma once

#include <memory>
#include "components/view_component.h"

namespace pl {

class Drawable {

public:
    void setViewComponent(ViewComponent view);
    const ViewComponent &getViewComponent();

private:
    ViewComponent view;
};
}
