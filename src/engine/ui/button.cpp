#include <string>
#include <memory>

#include "button.h"
#include <SFML/Graphics.hpp>

namespace pl {
namespace ui {

Button::Button(std::string value, sf::Vector2f position, std::string name,
               std::shared_ptr<sf::Font> font, sf::Color color, sf::Color activeColor, int size)
    : position{position}, name{name}, font{font}, active{false}, color{color}, activeColor{activeColor} {
    this->text.setString(value);
    this->text.setFont(*this->font);
    this->text.setColor(this->color);
    this->text.setPosition(this->position);
    this->text.setCharacterSize(static_cast<int>(size));
    this->bounds = this->text.getGlobalBounds();
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

void Button::draw(sf::RenderWindow &window) {
    window.draw(text);
}
}
}

