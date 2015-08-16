#include "drawable.h"
#include "components/view_component.h"

namespace pl {

void Drawable::setViewComponent(ViewComponent view) {
    this->view = view;
}

const ViewComponent &Drawable::getViewComponent() {
    return this->view;
}
}
