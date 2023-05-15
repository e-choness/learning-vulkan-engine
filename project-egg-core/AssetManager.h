#pragma once
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include<unordered_map>

class AssetManager
{
public:
	static SDL_Texture* loadImage(SDL_Renderer* renderer, const std::string& filename);
	static void destroyAssets();
private:
	static std::unordered_map<std::string, SDL_Texture*> textures;
};
#endif // ASSETMANAGER_H
