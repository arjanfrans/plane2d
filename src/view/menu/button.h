#ifndef VIEW_MENU_BUTTON_H
#define VIEW_MENU_BUTTON_H

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "../mouse_listener.h"

namespace view {
namespace menu {

class Button : public MouseListener {

public:
    Button(std::string value, sf::Vector2f position, std::string name, std::shared_ptr<sf::Font> font, sf::Color color,
           sf::Color activeColor, int size);
    void setActive(bool active);
    sf::Vector2f position;
    void draw(sf::RenderWindow &window);
    std::string name;

private:
    std::shared_ptr<sf::Font> font;
    sf::Text text;
    bool active;
    sf::Color color;
    sf::Color activeColor;
};
}
}
#endif
