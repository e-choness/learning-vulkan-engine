#include "Engine.h"

Engine* Engine::s_Instance = nullptr;

Engine::Engine() {
	SDL_Log("The engine now has the one and only instance.");
}

Engine* Engine::GetInstance()
{
	return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
}

bool Engine::Init()
{
	m_IsRunning = true;
	SDL_Log("The engine is initialized and running.");
	return m_IsRunning;
}

bool Engine::Clean()
{
	if(s_Instance) {
		delete s_Instance;
		s_Instance = nullptr;
		SDL_Log("The engine now has been cleaned.");
		return true;
	}	
	SDL_Log("The engine has trouble clean up everything.");
	return false;
}

void Engine::Quit()
{
	m_IsRunning = false;
	SDL_Log("The engine is quiting...");
}

void Engine::Update(float deltaTime)
{
	SDL_Log("The engine is updating now.");
}

void Engine::Render()
{
	SDL_Log("The engine will initiate renderer here.");
}

void Engine::Events()
{
	SDL_Log("The engine will handle events here.");
}

bool Engine::isRunning()
{
	return m_IsRunning;
}
