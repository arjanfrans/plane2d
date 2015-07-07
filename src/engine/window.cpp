#include "window.h"

namespace game {
namespace engine {

    Window::Window()
    : window_(nullptr, nullptr), surface_(nullptr, SDL_FreeSurface), width_(640), height_(480)
    {
    }

    bool Window::init() {
        window_ = std::unique_ptr<SDL_Window, void(*)(SDL_Window*)>(SDL_CreateWindow("SDL Example", 
                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_, height_, SDL_WINDOW_SHOWN), SDL_DestroyWindow);
        if(window_ == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return false;
        }

        // surface_ = SDL_GetWindowSurface(window_);
        SDL_Delay(2000);
        return true;
    }
}
}
