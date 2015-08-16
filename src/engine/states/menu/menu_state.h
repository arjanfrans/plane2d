#pragma once

#include <memory>
#include <vector>

#include "../state.h"
#include "../../engine.h"

#include "../../config.h"

#include "../../ui/button.h"


namespace pl {
class MenuInput;
class MenuView;

enum class MenuItem { START, OPTIONS, EXIT };

class MenuState : public State {

public:
    MenuState(std::shared_ptr<Engine> engine);
    void update(const float dt);
    void setInputs(std::vector<MenuInput> inputs);
    void setViews(std::vector<MenuView> view);
    std::vector<std::string> itemKeys;
    std::vector<std::string> items;
    void moveUp();
    void moveDown();
    void select();
    void setSelectedItem(std::string);
    void resizeWindow(float width, float height);
    int selectedItemIndex;
    std::string selectedItem;
    std::vector<std::shared_ptr<ui::Button>> getButtons();
    void updateInput(sf::Event event);

private:
    std::vector<MenuInput> inputs;
    std::vector<MenuView> views;
    void updateViews();
    void onStart();
    void onOptions();
    // virtual void onOptions() = 0;
};
}

