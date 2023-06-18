#include "Core/Engine.h"
#include "Timer/Timer.h"
#include <memory>

int main(int argc, char** argv) {

    // Check if SDL can initialize all components
    if (!SDL_Init(SDL_INIT_EVERYTHING)) {
        SDL_Log("SDL library is running.");
    }

    const std::unique_ptr<Engine> engine = std::make_unique<Engine>();


    // Initialize game engine instance and members
    // Set delta time for update

    // Handle game events, updates and render as long as the engine is running
    while (engine->isRunning()) {
        // Engine handles game events
        engine->Events();

        // Engine updates objects and entities movements
        engine->Update();

        // Engine renders updated states
        engine->Render();

        // Calculate framerate
        engine->Tick();
    }

    return 0;
}
