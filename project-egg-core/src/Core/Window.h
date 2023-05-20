#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <string>

class Window {
public:
    // Constructor
    Window(const std::string& title, int x, int y, int w, int h, Uint32 flags);

    // Destructor
    ~Window();

    // Returns a const pointer to the window
    SDL_Window* get() const;

private:
    // Pointer to the window
    SDL_Window* window;
};

#endif // WINDOW_H
