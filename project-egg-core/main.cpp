#include <iostream>
#include <SDL.h>
#include "Game.h"

int main(int argc, char* argv[]) {
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    // Create the game object
    Game game("Minimalist Game Engine", SCREEN_WIDTH, SCREEN_HEIGHT);

    // Initialize the game
    if (!game.init()) {
        return 1;
    }

    // Start the game loop
    game.run();

    // Clean up the game
    game.cleanup();

    return 0;
}
