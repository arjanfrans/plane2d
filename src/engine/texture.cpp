#include "texture.h"

namespace game {
namespace engine {

    Texture::Texture() 
    : surface_(SDL_LoadBMP("data/cube.bmp"), SDL_FreeSurface), width_{0}, height_{0}
    {
    }
}
}
