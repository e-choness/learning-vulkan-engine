#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

class Window {
public:
    // Constructor
    Window(const char* title, int x, int y, int w, int h, Uint32 flags);

    // Destructor
    ~Window();

    // Returns a const pointer to the window
    SDL_Window* GetInstance() const;

    // Returns window status
    inline bool IsRunning() { return m_IsRunning; }

private:  
    // Pointer to the window
    SDL_Window* s_window;

    bool m_IsRunning;
};

#endif // WINDOW_H
