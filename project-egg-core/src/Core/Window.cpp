#include "Window.h"

Window::Window(const std::string& title, int w, int h, Uint32 flags)
    : s_window(nullptr), m_IsRunning(true)
{
    // Create a window with the specified properties
    s_window = SDL_CreateWindow(title.c_str(), w, h, flags);
    if (!s_window) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s", SDL_GetError());
        m_IsRunning = false;
    }
}

Window::~Window() {
    if (s_window) {
        SDL_DestroyWindow(s_window);
    }
}

SDL_Window* Window::GetInstance() const {
    return s_window;
}
