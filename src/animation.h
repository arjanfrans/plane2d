#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
	public:
		Animation(int startFrame, int endFrame, float duration);

		int startFrame;
		int endFrame;
		float duration;

		int getLength();
};

#endif
