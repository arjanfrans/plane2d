#include "view.h"
namespace pl {

View::View(float virtualWidth, float virtualHeight)
    : virtualWidth{virtualWidth}, virtualHeight{virtualHeight} {
}

sf::FloatRect View::virtualResolutionViewport(float width, float height) {
    float virtualRatio = this->virtualWidth / this->virtualHeight;
    float ratio = width / height;
    float scale = 1;
    sf::Vector2f crop{0, 0};

    if (ratio > virtualRatio) {
        scale = height / this->virtualHeight;
        crop.x = ((width - (this->virtualWidth * scale)) / 2) / width;
    } else if (ratio < virtualRatio) {
        scale = width / this->virtualWidth;
        crop.y = ((height - (this->virtualHeight * scale)) / 2) / height;
    } else {
        scale = width / this->virtualWidth;
    }

    auto w = (this->virtualWidth * scale) / width;
    auto h = (this->virtualHeight * scale) / height;
    return sf::FloatRect(crop.x, crop.y, w, h);
}
}
