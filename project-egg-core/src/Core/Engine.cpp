#include "Engine.h"
#include "Graphics/AssetManager.h"
#include "Map/MapParser.h"

#include <memory>

Engine::Engine(): m_IsRunning(false), m_LevelMap(nullptr)
{
    // initialization check
    m_IsRunning = InitCheck();

	if (MapParser::GetInstance()->Load()) {
		SDL_Log("Failed to load the map. Error: %s", SDL_GetError());
	}

	m_LevelMap = MapParser::GetInstance()->GetMap("MAP");


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
    m_Renderer.SetDrawColor(124, 218, 254, 255);
    m_Renderer.ClearRender();
	m_LevelMap->Render();
	ghost.Render();
	m_Renderer.PresentRenderer();
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

Engine::~Engine() {
    Clean();
}
