#include <memory>

#include <SFML/Graphics.hpp>

#include "input.h"
#include "../engine.h"
#include "../utils/logger.h"

namespace pl {

Input::Input(std::shared_ptr<Engine> engine) : engine{engine} {
}
}
