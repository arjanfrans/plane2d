#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "GL/gl.h"


#include "renderer.h"
#include "engine.h"

namespace game {
namespace engine {

    Engine::Engine() 
    : renderer_()
    {}

    

    bool Engine::init() {
        return renderer_.init();
    }


    void Engine::render() {
        renderer_.render();
    }
}
}
