#include "Renderer.h"
#include "AssetManager.h"
#include <iostream>

Renderer::Renderer(SDL_Window* window, int index, Uint32 flags)
    : s_Renderer(nullptr), m_IsRunning(true)
{
    // Create a renderer for the specified window
    s_Renderer = SDL_CreateRenderer(window, index, flags);
    if (!s_Renderer) {
        SDL_Log("Renderer could not be created! Error: %s", SDL_GetError());
        m_IsRunning = false;
    }
}

Renderer::~Renderer() {
    if (s_Renderer) {
        SDL_DestroyRenderer(s_Renderer);
    }
}

SDL_Renderer* Renderer::GetInstance() const {
    return s_Renderer;
}

void Renderer::Render() {
    SDL_SetRenderDrawColor(s_Renderer, 124, 218, 254, 255);
    SDL_RenderClear(s_Renderer);
    AssetManager::GetInstance()->DrawTexture(s_Renderer, "ghost", 100, 100, 600, 660);
    SDL_RenderPresent(s_Renderer);
}

void Renderer::fillRect(SDL_Rect* rect)
{
    SDL_RenderFillRect(s_Renderer, rect);
}

void Renderer::drawCircle(int x, int y, int radius)
{
    //SDL_RenderDrawCircle(renderer, x, y, radius);
}

void Renderer::Clear() {
    SDL_RenderClear(s_Renderer);
}

