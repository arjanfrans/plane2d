#ifndef VIEW_MENU_BUTTON_H
#define VIEW_MENU_BUTTON_H

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "mouse_listener.h"

namespace pl {
namespace ui {

class Button : public MouseListener {

public:
    Button(std::string value, sf::Vector2f position, std::string name, std::shared_ptr<sf::Font> font,
           sf::Color color, sf::Color activeColor, int size);
    void setActive(bool active);
    const sf::Vector2f &getPosition();
    const sf::Text &getDrawable();
    std::string name;
    void setColor(sf::Color color);
    void setScale(float x, float y);
    const sf::Vector2f& getScale();
    bool overlaps(sf::Vector2f position);
    sf::FloatRect getBounds();

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
