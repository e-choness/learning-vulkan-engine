#pragma once

#include "SDL3/SDL.h"
#include <string>
#include "RenderProperties.h"

class Renderer {
public:
    // Constructor
    Renderer();

    // Destructor
    ~Renderer();

    // Get renderer instance
    SDL_Renderer* GetRenderer() { return m_Renderer; }

    // Set drawing color
    void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    // Draw Rectangle
    void DrawRectangle(RectProperties* srcProp, RectProperties* destProp, RenderProperties* renderProp);

    // Present renderer after settings
    void PresentRenderer();

    // Clears the renderer
    void ClearRender();

private:
    // SDL window
    SDL_Window* m_Window;

    // SDL renderer
    SDL_Renderer* m_Renderer;
};
