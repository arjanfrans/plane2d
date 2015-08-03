#ifndef PLANE_H
#define PLANE_H

#include <memory>

#include "engine/config.h"
#include "engine/game.h"

class Plane : public pl::Game {

public:
private:
    void createStates();
    void createMenuState();
};

#endif
