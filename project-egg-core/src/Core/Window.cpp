#include "Window.h"
#include <iostream>

Window::Window(const std::string& title, int x, int y, int w, int h, Uint32 flags)
    : window(nullptr)
{
    // Create a window with the specified properties
    window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
    if (!window) {
        std::cerr << "Window could not be created! Error: " << SDL_GetError() << std::endl;
    }
}

Window::~Window() {
    if (window) {
        SDL_DestroyWindow(window);
    }
}

SDL_Window* Window::get() const {
    return window;
}
