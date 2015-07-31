#include <memory>
#include "menu_view.h"

#include "../utils/logger.h"

namespace view {

MenuView::MenuView(std::shared_ptr<GameStateMenu> state) {
    this->state = state;
    if(!font.loadFromFile("data/fonts/font.ttf")) {
        LOG(FATAL) << "Unable to load font.";
        exit(EXIT_FAILURE);
    }
}


}
