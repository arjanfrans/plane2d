#include "GL/gl.h"

#include "renderer.h"
#include "window.h"
#include "engine.h"

namespace game {
namespace engine {

    Engine::Engine() 
    : window_(), renderer_()
    {}

    

    bool Engine::init() {
        return window_.init();
    }


    void Engine::render() {
    }
}
}
