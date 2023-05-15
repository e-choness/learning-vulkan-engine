#include "AssetManager.h"

SDL_Texture* AssetManager::loadImage(SDL_Renderer* renderer, const std::string& filename)
{
    if (textures.count(filename) == 0) {
        SDL_Surface* surface = IMG_Load(filename.c_str());
        if (surface == nullptr) {
            SDL_Log("Failed to load image %s: %s", filename.c_str(), SDL_GetError());
            return nullptr;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if (texture == nullptr) {
            SDL_Log("Failed to create texture from image %s: %s", filename.c_str(), SDL_GetError());
            return nullptr;
        }
        textures[filename] = texture;
    }
    return textures[filename];
}

void AssetManager::destroyAssets()
{
    for (auto it = textures.begin(); it != textures.end(); ++it) {
        SDL_DestroyTexture(it->second);
    }

    textures.clear();
}
