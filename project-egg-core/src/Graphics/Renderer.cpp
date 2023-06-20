#include "Renderer.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

Renderer::Renderer()
    : m_Renderer(nullptr), m_Window(nullptr)
{
    // Create a renderer for the specified window
    m_Window = SDL_CreateWindow("Egg Engine", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
    if (!m_Window){
        SDL_Log("Window could not be created! Error: %s", SDL_GetError());
    }
    m_Renderer = SDL_CreateRenderer(m_Window, nullptr, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!m_Renderer) {
        SDL_Log("Renderer could not be created! Error: %s", SDL_GetError());
    }
}

Renderer::~Renderer() {
    if (m_Renderer) {
        SDL_DestroyRenderer(m_Renderer);
        SDL_Log("The renderer now has been cleaned.");
    }

    if (m_Window) {
        SDL_DestroyWindow(m_Window);
        SDL_Log("The window now has been cleaned.");
    }
}

void Renderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
}

void Renderer::PresentRenderer(){
    SDL_RenderPresent(m_Renderer);
}

void Renderer::ClearRender() {
    SDL_RenderClear(m_Renderer);
}

void Renderer::DrawRectangle(RectProperties *srcProp, RectProperties *destProp, RenderProperties *renderProp) {
    auto srcRect = SDL_FRect {srcProp->X, srcProp->Y, srcProp->Width, srcProp->Height};
    auto destRect = SDL_FRect {destProp->X, destProp->Y, destProp->Width, destProp->Height};
    SDL_RenderTextureRotated(m_Renderer, renderProp->Texture, &srcRect, &destRect, renderProp->Angle, renderProp->Center, renderProp->Flip);
}

