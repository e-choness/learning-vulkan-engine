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

    // Initiatialize Input System
    inputSystem = new InputSystem();

    // Set the draw color to white
    renderer->setDrawColor(255, 255, 255, 255);

    // Set isRunning flag to true
    isRunning = true;

    return true;
}

void Game::run() {
    // Loop while the game is running
    while (!inputSystem->quitRequested()) {
        // Handle SDL events through Input System updates
        inputSystem->update();

        // Quit game if ESC is pressed
        if (inputSystem->keyPressed(SDLK_ESCAPE)) {
            break;
        }

        // Clear the renderer
        renderer->clear();

        // Set draw color of rectangular to black
        renderer->setDrawColor(0, 0, 0, 255);

        // Get the rectangular on the screen from (50, 50) to mouse position.
        SDL_Rect rect = { inputSystem->getMouseX(), inputSystem->getMouseY(), 50, 50 };

        // Fill the rectangular with black
        renderer->fillRect(&rect);

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

    if (inputSystem) {
        delete inputSystem;
        inputSystem = nullptr;
    }

    // Quit SDL
    SDL_Quit();
}

