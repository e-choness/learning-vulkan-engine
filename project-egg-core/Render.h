#ifndef RENDER_H
#define RENDER_H

#include <SDL.h>

class Render {
public:
    // Constructor
    Render(SDL_Window* window, int index, Uint32 flags);

    // Destructor
    ~Render();

    // Clears the renderer
    void clear();

    // Presents the renderer to the screen
    void present();

    // Sets the drawing color of the renderer
    void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    // Fill a rectangular with color
    void fillRect(SDL_Rect* rect);

    void drawCircle(int x, int y, int radius);

    // Returns a const pointer to the renderer
    SDL_Renderer* get() const;

private:
    // Pointer to the renderer
    SDL_Renderer* renderer;
};

#endif // RENDER_H
