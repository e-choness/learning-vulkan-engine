#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <string>
#include "Core/Engine.h"

class AssetManager {
public:
	static AssetManager* GetInstance() {
		return s_Instance = (s_Instance != nullptr)? s_Instance: new AssetManager();
	}

	bool LoadTexture(std::string id, std::string filename);
	
	void DropTexture(std::string id);
	
	void CleanTexture();

	void DrawTexture(std::string id, float x, float y, float width, float height, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void DrawFrame(std::string id, float x, float y, float width, float height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void DrawTile(std::string tilesetId, int tileSize, float x, float y, float width, float height, int row, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	AssetManager();
	static AssetManager* s_Instance;

	std::map<std::string, SDL_Texture*> m_TextureMap;
};
