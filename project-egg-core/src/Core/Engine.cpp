#include "Engine.h"
#include "Graphics/AssetManager.h"
#include "Map/MapParser.h"

#include <memory>

Engine::Engine(): m_Window(nullptr), m_Renderer(nullptr), m_IsRunning(false), m_LevelMap(nullptr)
{
    // initialization check
    m_IsRunning = InitCheck();

	// Set window flags
	auto window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
	
	// Initialize display window
    m_Window = SDL_CreateWindow("Egg Engine", SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);

    // Set renderer flags
    auto render_flags = (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Initialize renderer in the window
	m_Renderer = SDL_CreateRenderer(m_Window,nullptr, render_flags);


	if (MapParser::GetInstance()->Load()) {
		SDL_Log("Failed to load the map. Error: %s", SDL_GetError());
	}

	m_LevelMap = MapParser::GetInstance()->GetMap("MAP");

    // Asset manager gets the renderer
    m_AssetManager.SetRenderer(m_Renderer);

	// Load character textures
    m_AssetManager.LoadTexture("ghost-floating",
                                             R"(D:\project-egg\project-egg-core\assets\characters\ghost-sheet.png)");
	m_AssetManager.LoadTexture("ghost-running", R"(D:\project-egg\project-egg-core\assets\characters\ghost-run-sheet.png)");

	
	Transform transform;
	transform.Log("This transformation is: ");

}

bool Engine::Clean()
{

    ghost.Clean();
    SDL_Log("The ghost textures now have been cleaned.");


	if (m_Renderer) {
		SDL_DestroyRenderer(m_Renderer);
		SDL_Log("The renderer now has been cleaned.");
	}

	if (m_Window) {
		SDL_DestroyWindow(m_Window);
		SDL_Log("The window now has been cleaned.");
	}

	m_AssetManager.CleanTexture();
	SDL_Log("The asset manager now has been cleaned.");

	IMG_Quit();
	SDL_Quit();

	SDL_Log("The engine has trouble clean up everything.");
	return false;
}

void Engine::Quit()
{
	m_IsRunning = false;
	SDL_Log("The engine is quiting...");
}

void Engine::Update()
{
	float deltaTime = m_Timer.GetDeltaTime();
	m_LevelMap->Update();
	ghost.Update(deltaTime);
}

void Engine::Render()
{
	//SDL_Log("The engine is rendering images.");
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderClear(m_Renderer);
	m_LevelMap->Render();
	ghost.Render();
	SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{	
	// Listening to game events
	InputSystem::GetInstance()->Listen();
}

void Engine::Tick(){
    m_Timer.Tick();
}

bool Engine::InitCheck() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return false;
	}

	SDL_Log("The engine is initialized and running.");
	return true;
}

SDL_Renderer* Engine::GetRenderer()
{
	return m_Renderer;
}

Engine::~Engine() {
    Clean();
}
