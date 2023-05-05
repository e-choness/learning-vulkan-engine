#include "Game.h"
#include <iostream>

Game::Game(const char* title, int width, int height) {
    window = std::make_unique<Window>(title, width, height);
    renderer = std::make_unique<Renderer>(window->get(), -1, SDL_RENDERER_ACCELERATED);
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!window->init()) {
        return false;
    }

    return true;
}

void Game::run() {
    running = true;
    while (running) {
        // Poll for events (in this case, just the "QUIT" event)
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear the screen to black
        SDL_SetRenderDrawColor(renderer->get(), 0, 0, 0, 255);
        SDL_RenderClear(renderer->get());

        // Game logic and rendering code here...

        // Update the screen
        SDL_RenderPresent(renderer->get());
    }
}

void Game::cleanup() {
    SDL_Quit();
}

