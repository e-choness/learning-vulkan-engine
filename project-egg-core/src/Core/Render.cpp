#include "Render.h"
#include <iostream>

Render::Render(SDL_Window* window, int index, Uint32 flags)
    : renderer(nullptr)
{
    // Create a renderer for the specified window
    renderer = SDL_CreateRenderer(window, index, flags);
    if (!renderer) {
        std::cerr << "Renderer could not be created! Error: " << SDL_GetError() << std::endl;
    }
}

Render::~Render() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
}

void Render::clear() {
    SDL_RenderClear(renderer);
}

void Render::present() {
    SDL_RenderPresent(renderer);
}

void Render::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Render::fillRect(SDL_Rect* rect)
{
    SDL_RenderFillRect(renderer, rect);
}

void Render::drawCircle(int x, int y, int radius)
{
    //SDL_RenderDrawCircle(renderer, x, y, radius);
}

SDL_Renderer* Render::get() const {
    return renderer;
}
