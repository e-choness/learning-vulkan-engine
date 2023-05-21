#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include<SDL.h>
#include<SDL_image.h>

#include"Window.h"
#include"Renderer.h"
#include"EventsHandler.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

class Engine
{
public:	
	static Engine* GetInstance();

	bool Init();
	bool Clean();
	void Quit();


	void Update(float deltaTime);
	void Render();
	void Events();

	inline bool isRunning() { return m_IsRunning; }

	Renderer* GetRenderer();

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
};

#endif // ENGINE_H

