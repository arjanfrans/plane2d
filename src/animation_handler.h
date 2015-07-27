#ifndef ANIMATION_HANDLER_H
#define ANIMATION_HANDLER_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "animation.h"

class AnimationHandler {

	private:
		std::vector<std::unique_ptr<Animation>> animations;
		float time;
		int currentAnimation;

	public:
		AnimationHandler();

		void addAnimation(std::unique_ptr<Animation> animation);
		void update(const float dt);
		void changeAnimation(int animationIndex);
		Animation* getCurrentAnimation();
		sf::IntRect bounds;
		sf::IntRect frameSize;
};

#endif
