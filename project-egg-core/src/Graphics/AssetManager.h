#pragma once
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include<SDL.h>
#include<SDL_image.h>
#include<map>
#include<string>
#include"Engine.h"

class AssetManager {
public:
	static AssetManager* GetInstance() {
		return s_Instance = (s_Instance != nullptr)? s_Instance: new AssetManager();
	}

	bool LoadTexture(std::string id, std::string filename);
	
	void DropTexture(std::string id);
	
	void CleanTexture();

	void DrawTexture(std::string id, float x, float y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void DrawFrame(std::string id, float x, float y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	AssetManager();
	static AssetManager* s_Instance;

	std::map<std::string, SDL_Texture*> m_TextureMap;
};

#endif // ASSETMANAGER_H
