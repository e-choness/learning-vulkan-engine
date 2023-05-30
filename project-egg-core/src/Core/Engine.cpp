#include "Engine.h"


Engine* Engine::s_Instance = nullptr;

Engine::Engine(): m_window(nullptr), m_renderer(nullptr), m_IsRunning(false), m_EventsHandler(nullptr) {
	SDL_Log("The engine now has the one and only instance.");
}

Engine* Engine::GetInstance()
{
	return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
}

bool Engine::Init()
{
	// Check
	m_IsRunning = InitCheck();
	if (!m_IsRunning) { return m_IsRunning; }
	
	// Initialize display window
	m_window = new Window("Egg Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// Initialize renderer in the window
	m_renderer = new Renderer(m_window->GetInstance(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	m_IsRunning = m_window->IsRunning() && m_renderer->IsRunning();

	m_EventsHandler = new EventsHandler();

	m_IsRunning = AssetManager::GetInstance()->LoadTexture("ghost", "assets/characters/ghost.png");
	
	
	Transform transform;
	transform.Log("This tranformation is: ");
	
	return m_IsRunning;
}

bool Engine::Clean()
{
	if (AssetManager::GetInstance()) {
		AssetManager::GetInstance()->CleanTexture();
		SDL_Log("The textures now have been cleaned.");
	}

	if (m_EventsHandler) {
		delete m_EventsHandler;
		SDL_Log("The events handler now has been cleaned.");
	}

	if (m_renderer) {
		delete m_renderer;
		SDL_Log("The renderer now has been cleaned.");
	}

	if (m_window) {
		delete m_window;
		SDL_Log("The window now has been cleaned.");
	}

	IMG_Quit();
	SDL_Quit();

	if (s_Instance) {
		delete s_Instance;
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
	//SDL_Log("The engine is updating now.");
}

void Engine::Render()
{
	//SDL_Log("The engine is renderering images.");
	m_renderer->Render();
}

void Engine::Events()
{
	//SDL_Log("The engine handles events here.");
	
	// 
	m_EventsHandler->QuitEvent();
	m_IsRunning = m_EventsHandler->IsRunning();
}

bool Engine::InitCheck() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to initilize SDL: %s", SDL_GetError());
		return false;
	}

	SDL_Log("The engine is initialized and running.");
	return true;
}


Renderer* Engine::GetRenderer()
{
	return m_renderer;
}