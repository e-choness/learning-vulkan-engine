#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>
#include <string>

class AssetManager {
public:
    explicit AssetManager(SDL_Renderer* renderer);

    void SetRenderer(SDL_Renderer* renderer) { m_Renderer = renderer; }

	bool LoadTexture(const std::string& id, const std::string& filename);

    SDL_Texture* GetTexture(const std::string& id);

	void DropTexture(const std::string& id);
	
	void CleanTexture();

    //XXX TO BE DELETED
	void DrawTexture(const std::string& id, float x, float y, float width, float height, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void DrawFrame(const std::string& id, float x, float y, float width, float height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void DrawTile(const std::string& tilesetId, int tileSize, float x, float y, float width, float height, int row, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
    SDL_Renderer* m_Renderer;

	std::unordered_map<std::string, SDL_Texture*> m_TextureMap;
};
