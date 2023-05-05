#include "Renderer.h"
#include <iostream>

Renderer::Renderer(SDL_Window* window, int index, Uint32 flags) {
    sdlRenderer.reset(SDL_CreateRenderer(window, index, flags));
    if (sdlRenderer == nullptr) {
        std::cerr << "Renderer could not be created! Error: " << SDL_GetError() << std::endl;
    }
}

SDL_Renderer* Renderer::get() const {
    return sdlRenderer.get();
}
