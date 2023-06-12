#pragma once
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include<SDL.h>
#include<SDL_image.h>
#include<map>
#include"Engine.h"

class AssetManager {
public:
	static AssetManager* GetInstance() {
		return s_Instance = (s_Instance != nullptr)? s_Instance: new AssetManager();
	}

	bool LoadTexture(const char* id, const char* filename);
	
	void DropTexture(const char* id);
	
	void CleanTexture();

	void DrawTexture(const char* id, float x, float y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void DrawFrame(const char* id, float x, float y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	AssetManager();
	static AssetManager* s_Instance;

	std::map<const char*, SDL_Texture*> m_TextureMap;
};

#endif // ASSETMANAGER_H
