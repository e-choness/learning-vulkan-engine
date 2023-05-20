#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Render.h"
#include "InputSystem.h"
#include "AssetManager.h"

class Game {
public:
    static Game* GetInstance() {
        return game_Instance = (game_Instance != nullptr) ? game_Instance : new Game();
    }

    // Initializes the game
    bool init();

    // Runs the game
    void run();

    // Cleans up the game
    void cleanup();

private:
    // Constructor
    Game();

    // Destructor
    ~Game();

    //Create a static Game instance
    static Game* game_Instance;

    // Pointer to the window
    Window* window;

    // Pointer to the renderer
    Render* renderer;

    // Input system 
    InputSystem* inputSystem;

    // Asset Manager
    //AssetManager* assetManager;

    // Flag to indicate if the game is running
    bool isRunning;
};
#endif // GAME_H
