#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Render.h"
#include "InputSystem.h"
#include "AssetManager.h"

class Game {
public:
    // Constructor
    Game();

    // Destructor
    ~Game();

    // Initializes the game
    bool init();

    // Runs the game
    void run();

    // Cleans up the game
    void cleanup();

private:
    // Pointer to the window
    Window* window;

    // Pointer to the renderer
    Render* renderer;

    // Input system 
    InputSystem* inputSystem;

    // Asset Manager
    AssetManager* assetManager;

    // Flag to indicate if the game is running
    bool isRunning;
};
#endif // GAME_H
