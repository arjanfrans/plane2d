#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "GL/gl.h"


#include "renderer.h"
#include "engine.h"

namespace game {
namespace engine {

    Engine::Engine() 
    : renderer()
    {}

    

    bool Engine::init() {
        return true; 
    }


    void Engine::render() {

    }
}
}
