#include "Game.h"
#include <iostream>

Game::Game()
    : window(nullptr), renderer(nullptr), inputSystem(nullptr), isRunning(false)
{
}

Game::~Game() {
    cleanup();
}

bool Game::init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return false;
    }

    // Create the window
    window = new Window("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s", SDL_GetError());
        return false;
    }

    // Create the renderer
    renderer = new Renderer(window->GetInstance(), -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
        return false;
    }

    // Initialize Input System
    inputSystem = new InputSystem();

    // Set isRunning flag to true
    isRunning = true;

    return true;
}

void Game::run() {

        // Clear the renderer
        renderer->Clear();

        // Get the rectangular on the screen from (50, 50) to mouse position.
        SDL_Rect rect = { inputSystem->getMouseX(), inputSystem->getMouseY(), 50, 50 };

        // Fill the rectangular with black
        renderer->fillRect(&rect);

        // Present the renderer to the screen
        renderer->Render();
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

    if (inputSystem) {
        delete inputSystem;
        inputSystem = nullptr;
    }

    // Quit SDL
    SDL_Quit();
}

