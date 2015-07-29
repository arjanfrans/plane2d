#include "animation.h"

Animation::Animation(int startFrame, int endFrame, float duration)
    : startFrame{ startFrame }
    , endFrame{ endFrame }
    , duration{ duration }
{
}

int Animation::getLength()
{
    return endFrame - startFrame + 1;
}
