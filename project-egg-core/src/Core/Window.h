#pragma once

#include <SDL.h>
#include <iostream>
#include <string>

class Window {
public:
    // Constructor
    Window(const std::string& title, int w, int h, Uint32 flags);

    // Destructor
    ~Window();

    // Returns a const pointer to the window
    [[nodiscard]] SDL_Window* GetInstance() const;

    // Returns window status
    [[nodiscard]] inline bool IsRunning() const { return m_IsRunning; }

private:  
    // Pointer to the window
    SDL_Window* s_window;

    bool m_IsRunning;
};