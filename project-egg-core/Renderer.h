#ifndef RENDERER_H
#define RENDERER_H

#include <memory>
#include <SDL.h>
#include "Window.h"

class Renderer {
public:
    Renderer(SDL_Window* window, int index, Uint32 flags);
    SDL_Renderer* get() const;

private:
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> sdlRenderer{ nullptr, SDL_DestroyRenderer };
};

#endif
