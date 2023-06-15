#pragma once

#include <SDL.h>
#include <iostream>
#include <string>

class Window {
public:
    // Constructor
    Window(std::string title, int w, int h, Uint32 flags);

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