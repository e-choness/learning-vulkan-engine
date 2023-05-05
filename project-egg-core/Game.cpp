#include "Game.h"
#include <iostream>

Game::Game()
    : window(nullptr), renderer(nullptr), isRunning(false)
{
}

Game::~Game() {
    cleanup();
}

bool Game::init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create the window
    window = new Window("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create the renderer
    renderer = new Render(window->get(), -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Set the draw color to white
    renderer->setDrawColor(255, 255, 255, 255);

    // Set isRunning flag to true
    isRunning = true;

    return true;
}

void Game::run() {
    // Loop while the game is running
    while (isRunning) {
        // Handle SDL events
        handleEvents();

        // Clear the renderer
        renderer->clear();

        // Draw game objects

        // Present the renderer to the screen
        renderer->present();
    }
}

void Game::cleanup() {
    // Destroy the renderer
    if (renderer) {
        delete renderer;
        renderer = nullptr;
    }

    // Destroy the window
    if (window) {
        delete window;
        window = nullptr;
    }

    // Quit SDL
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }
    }
}
