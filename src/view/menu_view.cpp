#include <memory>
#include "menu_view.h"

namespace view {

MenuView::MenuView(std::shared_ptr<GameStateMenu> state) {
    this->state = state;
}

}
