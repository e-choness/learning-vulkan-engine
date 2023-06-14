#pragma once

#include <SDL.h>

class Renderer {
public:
    // Constructor
    Renderer(SDL_Window* window, int index, Uint32 flags);

    // Destructor
    ~Renderer();

    // Returns renderer instance
    SDL_Renderer* GetInstance() const;

    // Returns renderer running status
    inline bool IsRunning() { return m_IsRunning; }

    // Presents the renderer to the screen
    void Render();

    // Fill a rectangular with color
    void fillRect(SDL_Rect* rect);

    void drawCircle(int x, int y, int radius);

    // Clears the renderer
    void Clear();

private:
    // A renderer instance
    SDL_Renderer* s_Renderer;

    // A flag indicates the renderer is running
    bool m_IsRunning;
};
