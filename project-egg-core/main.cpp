#include "Engine.h"

int main(int argc, char** argv) {

    // Check if SDL can initialize all components
    if (!SDL_Init(SDL_INIT_EVERYTHING)) {
        SDL_Log("SDL library is running righty.");
    }

    // Initialize game engine instance and members
    Engine::GetInstance()->Init();

    // Set delta time for udpate
    float m_DeltaTime = 0.0f;

    // Handle game events, updates and render as long as the engine is running
    while (Engine::GetInstance()->isRunning()) {
        // Engine handles game events
        Engine::GetInstance()->Events();

        // Engine updates objects and entities movements
        Engine::GetInstance()->Update(m_DeltaTime);

        // Engine renders updated states
        Engine::GetInstance()->Render();

        // Quit game
        //Engine::GetInstance()->Quit();
    }

    // Clean up engine instances and members
    Engine::GetInstance()->Clean();

    return 0;
}
