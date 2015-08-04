#include <string>
#include <memory>

#include "button.h"
#include <SFML/Graphics.hpp>
#include "../utils/logger.h"

namespace pl {
namespace ui {

Button::Button(std::string value, sf::Vector2f position, std::string name,
               std::shared_ptr<sf::Font> font, sf::Color color, sf::Color activeColor, int size)
    : name{name}, font{font}, active{false}, color{color}, activeColor{activeColor} {
    this->text.setString(value);
    this->text.setFont(*this->font);
    this->text.setColor(this->color);
    this->text.setPosition(position);
    this->text.setCharacterSize(static_cast<int>(size));
}

void Button::setColor(sf::Color color) {
    this->color = color;
    this->text.setColor(this->color);
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

const sf::Vector2f &Button::getPosition() {
    return this->text.getPosition();
}


void Button::setScale(float x, float y) {
    this->text.setScale(x, y);
    return;
}

const sf::Vector2f& Button::getScale() {
    return this->text.getScale();
}

const sf::Text &Button::getDrawable() {
    return this->text;
}

bool Button::overlaps(sf::Vector2f position) {
    return getBounds().contains(position);
}

sf::FloatRect Button::getBounds() {
    return this->text.getGlobalBounds();
}
}
}

