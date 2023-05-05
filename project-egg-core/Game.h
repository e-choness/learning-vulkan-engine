#ifndef GAME_H
#define GAME_H

#include <memory>
#include <SDL.h>
#include "Window.h"
#include "Renderer.h"

class Game {
public:
    Game(const char* title, int width, int height);
    bool init();
    void run();
    void cleanup();

private:
    std::unique_ptr<Window> window{ nullptr };
    std::unique_ptr<Renderer> renderer{ nullptr };
    bool running{ false };
};

#endif
