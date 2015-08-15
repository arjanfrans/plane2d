#pragma once

#include "entity.h"
#include "drawable.h"
#include "movable_entity.h"
#include "controllable.h"

namespace pl {

class Player : public MovableEntity, public Drawable, public Controllable {};
}
