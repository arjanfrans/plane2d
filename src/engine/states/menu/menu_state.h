#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <memory>
#include <vector>

#include "../state_manager.h"
#include "../state.h"

#include "menu_input.h"
#include "menu_view.h"
#include "../../ui/button.h"

namespace pl {
class MenuInput;
class MenuView;
enum class MenuItem { START, OPTIONS, EXIT };

class MenuState : public State {

public:
    MenuState(std::shared_ptr<StateManager> stateManager);
    void update(const float dt);
    void setInputs(std::vector<MenuInput> inputs);
    void setViews(std::vector<MenuView> view);
    std::vector<std::string> itemKeys;
    std::vector<std::string> items;
    void moveUp();
    void moveDown();
    void select();
    void setSelectedItem(std::string);
    int selectedItemIndex;
    std::string selectedItem;
    std::vector<std::shared_ptr<ui::Button>> getButtons();

private:
    std::vector<MenuInput> inputs;
    std::vector<MenuView> views;
    void updateInputs();
    void updateViews();
};
}

#endif
