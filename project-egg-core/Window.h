#ifndef WINDOW_H
#define WINDOW_H

#include <memory>
#include <SDL.h>

class Window {
public:
    Window(const char* title, int width, int height);
    bool init();
    SDL_Window* get() const;

private:
    const char* title;
    int width;
    int height;
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> sdlWindow{ nullptr, SDL_DestroyWindow };
};

#endif
