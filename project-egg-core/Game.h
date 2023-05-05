#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Render.h"

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

    // Flag to indicate if the game is running
    bool isRunning;

    // Handles SDL events
    void handleEvents();
};

#endif // GAME_H
