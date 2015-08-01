#include <string>
#include <memory>

#include "button.h"
#include <SFML/Graphics.hpp>

namespace view {
namespace menu {

Button::Button(std::string value, sf::Vector2f position, std::shared_ptr<sf::Font> font, sf::Color color,
               sf::Color activeColor, int size)
    : position{position}, font{font}, active{false}, color{color}, activeColor{activeColor} {
    this->text.setString(value);
    this->text.setFont(*this->font);
    this->text.setColor(this->color);
    this->text.setPosition(this->position);
    this->text.setCharacterSize(static_cast<int>(size));
}

void Button::setActive(bool active) {
    if (active && !this->active) {
        this->text.setColor(activeColor);
        this->active = true;
    } else if (!active && this->active) {
        this->text.setColor(color);
        this->active = false;
    }
    return;
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(text);
}
}
}

