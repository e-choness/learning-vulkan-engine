#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Window.h"
#include "Renderer.h"
#include "EventsHandler.h"

#include "Physics/Vector2D.h"
#include "Physics/Transform.h"

#include "Inputs/InputSystem.h"

#include "Timer/Timer.h"

#include "Characters/Ghost.h"

#include "Map/GameMap.h"
#include "Map/MapParser.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

class AssetManager;
class Engine
{
public:	
	static Engine* GetInstance();

	bool Init();
	bool Clean();
	void Quit();


	void Update();
	void Render();
	void Events();

	inline bool isRunning() { return m_IsRunning; }

	SDL_Renderer* GetRenderer();

protected:
	

private:
	// The engine onstructor
	Engine();

	bool InitCheck();

	// The flag which indicates the engine is running
	bool m_IsRunning;

	// The only engine instance here
	static Engine* s_Instance;

	// Window
	Window* m_window;

	// Renderer
	Renderer* m_renderer;

	// Events Handler
	EventsHandler* m_EventsHandler;

	// Game Map
	GameMap* m_LevelMap;
};

