#include "AssetManager.h"

AssetManager* AssetManager::s_Instance = nullptr;

//SDL_Texture* AssetManager::loadImage(SDL_Renderer* renderer, const std::string& filename)
//{
//    if (textures.count(filename) == 0) {
//        SDL_Surface* surface = IMG_Load(filename.c_str());
//        if (surface == nullptr) {
//            SDL_Log("Failed to load image %s: %s", filename.c_str(), SDL_GetError());
//            return nullptr;
//        }
//
//        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
//        SDL_FreeSurface(surface);
//
//        if (texture == nullptr) {
//            SDL_Log("Failed to create texture from image %s: %s", filename.c_str(), SDL_GetError());
//            return nullptr;
//        }
//        textures[filename] = texture;
//    }
//    return textures[filename];
//}

//void AssetManager::destroyAssets()
//{
//    for (auto it = textures.begin(); it != textures.end(); ++it) {
//        SDL_DestroyTexture(it->second);
//    }
//
//    textures.clear();
//}
AssetManager::AssetManager() {

}

bool AssetManager::LoadTexture(const char* id, const char* filename)
{
	SDL_Surface* surface = IMG_Load(filename);
	if (surface == nullptr) {
		SDL_Log("Failed to load texture: %s, %s", filename, SDL_GetError());
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer()->GetInstance(), surface);
	SDL_FreeSurface(surface);

	if (texture == nullptr) {
		SDL_Log("Failed to create texture from image %s: %s", filename, SDL_GetError());
		return false;
	}

	m_TextureMap[id] = texture;
	return true;
}

void AssetManager::DrawTexture(SDL_Renderer* renderer, const char* id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { 0, 0, width, height };
	SDL_Rect destRect = { x, y, width, height };
	SDL_RenderCopyEx(renderer, m_TextureMap[id], &srcRect, &destRect, 0.0, nullptr, flip);
}

void AssetManager::DripTexture(const char* id)
{
}

void AssetManager::CleanTexture()
{
    for (auto it = m_TextureMap.begin(); it != m_TextureMap.end(); ++it) {
        SDL_DestroyTexture(it->second);
    }

	m_TextureMap.clear();
}


