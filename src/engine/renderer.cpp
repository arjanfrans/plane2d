#include "renderer.h"

namespace game {
namespace engine {

    Renderer::Renderer()
    : window_(NULL), surface_(NULL), screen_width_(640), screen_height_(480)
    {

    }

    Renderer::~Renderer() {
        SDL_DestroyWindow(window_);
    }

    bool Renderer::init() {
        window_ = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width_, screen_height_, SDL_WINDOW_SHOWN);
        if(window_ == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return false;
        }
        surface_ = SDL_GetWindowSurface(window_);
        SDL_FillRect(surface_, NULL, SDL_MapRGB(surface_->format, 0xFF, 0xFF, 0xFF));
        SDL_UpdateWindowSurface(window_);
        SDL_Delay(2000);
        // return true;
    }

    void Renderer::render() {

    }
}
}
