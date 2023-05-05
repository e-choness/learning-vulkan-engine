#include "Window.h"
#include <iostream>

Window::Window(const char* title, int width, int height) : title(title), width(width), height(height) {}

bool Window::init() {
    sdlWindow.reset(SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN));
    if (sdlWindow == nullptr) {
        std::cerr << "Window could not be created! Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

SDL_Window* Window::get() const {
    return sdlWindow.get();
}
