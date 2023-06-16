#include "AssetManager.h"

AssetManager::AssetManager() {

}

bool AssetManager::LoadTexture(const std::string& id, const std::string& filename)
{
	SDL_Surface* surface = IMG_Load(filename.c_str());
	if (surface == nullptr) {
		SDL_Log("Failed to load texture: %s, %s", filename.c_str(), SDL_GetError());
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_DestroySurface(surface);

	if (texture == nullptr) {
		SDL_Log("Failed to create texture from image %s: %s", filename.c_str(), SDL_GetError());
		return false;
	}

	m_TextureMap[id] = texture;
	return true;
}

void AssetManager::DrawTexture(const std::string& id, float x, float y, float width, float height, SDL_RendererFlip flip)
{
    SDL_FRect srcRect = { 0, 0, width, height };
    SDL_FRect destRect = { x, y, width, height };
	SDL_RenderTextureRotated(m_renderer, m_TextureMap[id], &srcRect, &destRect, 0.0, nullptr, flip);
}

void AssetManager::DrawFrame(const std::string& id, float x, float y, float width, float height, int row, int frame, SDL_RendererFlip flip)
{
    SDL_FRect srcRect = { width * static_cast<float>(frame), height * static_cast<float>(row-1), width, height };
    SDL_FRect destRect = { x, y, width, height };
    SDL_RenderTextureRotated(m_renderer, m_TextureMap[id], &srcRect, &destRect, 0.0, nullptr, flip);
}

void AssetManager::DrawTile(const std::string& tilesetId, int tileSize, float x, float y, float width, float height, int row, SDL_RendererFlip flip)
{
    SDL_FRect srcRect = { x, y, static_cast<float>(tileSize), static_cast<float>(tileSize) };
    SDL_FRect destRect = { static_cast<float>(tileSize), static_cast<float>(tileSize*(row-1)), static_cast<float>(tileSize), static_cast<float>(tileSize) };
    SDL_RenderTextureRotated(m_renderer, m_TextureMap[tilesetId], &srcRect, &destRect, 0.0, nullptr, flip);
}

void AssetManager::DropTexture(const std::string& id)
{
	SDL_DestroyTexture(m_TextureMap[id]);
	m_TextureMap.erase(id);
}

void AssetManager::CleanTexture()
{
    for (auto & it : m_TextureMap) {
        SDL_DestroyTexture(it.second);
    }

	m_TextureMap.clear();
}


