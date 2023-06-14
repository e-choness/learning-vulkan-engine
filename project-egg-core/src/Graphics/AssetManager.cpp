#include "AssetManager.h"

AssetManager* AssetManager::s_Instance = nullptr;

AssetManager::AssetManager() {

}

bool AssetManager::LoadTexture(std::string id, std::string filename)
{
	SDL_Surface* surface = IMG_Load(filename.c_str());
	if (surface == nullptr) {
		SDL_Log("Failed to load texture: %s, %s", filename.c_str(), SDL_GetError());
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
	SDL_FreeSurface(surface);

	if (texture == nullptr) {
		SDL_Log("Failed to create texture from image %s: %s", filename.c_str(), SDL_GetError());
		return false;
	}

	m_TextureMap[id] = texture;
	return true;
}

void AssetManager::DrawTexture(std::string id, float x, float y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { 0, 0, width, height };
	SDL_Rect destRect = { static_cast<int>(x), static_cast<int>(y), width, height };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &destRect, 0.0, nullptr, flip);
}

void AssetManager::DrawFrame(std::string id, float x, float y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { width * frame, height * (row-1), width, height };
	SDL_Rect destRect = { static_cast<int>(x), static_cast<int>(y), width, height };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &destRect, 0.0, nullptr, flip);
}

void AssetManager::DrawTile(std::string tilesetId, int tileSize, float x, float y, int width, int height, int row, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { static_cast<int>(x), static_cast<int>(y), tileSize, tileSize };
	SDL_Rect destRect = { tileSize, tileSize*(row-1), tileSize, tileSize };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[tilesetId], &srcRect, &destRect, 0.0, nullptr, flip);
}

void AssetManager::DropTexture(std::string id)
{
	SDL_DestroyTexture(m_TextureMap[id]);
	m_TextureMap.erase(id);
}

void AssetManager::CleanTexture()
{
    for (auto it = m_TextureMap.begin(); it != m_TextureMap.end(); ++it) {
        SDL_DestroyTexture(it->second);
    }

	m_TextureMap.clear();
}


