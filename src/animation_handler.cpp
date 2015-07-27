#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "animation.h"
#include "animation_handler.h"

AnimationHandler::AnimationHandler() {
}

Animation* AnimationHandler::getCurrentAnimation() {
	return animations[currentAnimation].get();
}

void AnimationHandler::addAnimation(std::unique_ptr<Animation> animation) {
	animations.push_back(std::move(animation));
}

void AnimationHandler::update(const float dt) {
	if(currentAnimation >= static_cast<int>(animations.size()) || currentAnimation < 0) {
		return;
	}

	auto duration = getCurrentAnimation()->duration;

	if((time + dt) / duration > (time /duration)) {
		auto frame = (time / dt) / duration;

		frame = static_cast<int>(frame) % getCurrentAnimation()->getLength();
		sf::IntRect rect{frameSize};
		rect.left = rect.width * frame;
		rect.top = rect.height * currentAnimation;
		bounds = rect;
	}

	time = time + dt;

	if(time > (duration * getCurrentAnimation()->getLength())) {
		time = 0.0f;
	}
	return;
}

void AnimationHandler::changeAnimation(int animationIndex) {
	if(currentAnimation == animationIndex || animationIndex >= static_cast<int>(animations.size())
			|| animationIndex < 0) {
		return;
	}

	currentAnimation = animationIndex;
	sf::IntRect rect{frameSize};
	rect.top = rect.height * animationIndex;
	bounds = rect;
	time = 0.0;
	return;
}

