#pragma once

#include <SDL.h>
#include <Graphics/AssetManager.h>
#include "Timer/Timer.h"
#include "Map/GameMap.h"
#include "Characters/Ghost.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

class Engine
{
public:
    // The engine constructor
    Engine();
    ~Engine();

    // Init Check
    static bool InitCheck();

    // Game cleanup functions.
	bool Clean();
	void Quit();

    // Game loop events.
	void Update();
	void Render();
	static void Events();
    void Tick();

    // Game running flag.
	[[nodiscard]] bool isRunning() const { return m_IsRunning; }

    // Game renderer getter.
	SDL_Renderer* GetRenderer();

private:
	// The flag which indicates the engine is running
	bool m_IsRunning;

    // Window
    SDL_Window* m_Window;

    // Renderer
    SDL_Renderer* m_Renderer;

	// Game Map
	GameMap* m_LevelMap;

    // Asset Manager
    AssetManager m_AssetManager;

    // Framerate timer
    Timer m_Timer;

    // testing members
    Properties ghostProperties = Properties("ghost-floating", 100.0f, 50.0f, 50, 55);
    Ghost ghost = Ghost(&ghostProperties);

};

