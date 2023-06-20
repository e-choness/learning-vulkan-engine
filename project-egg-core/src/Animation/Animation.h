#pragma once

#include <SDL.h>
#include <string>

#include "Graphics/AssetManager.h"

class Animation {
public:
	Animation(std::string &mTextureId);

	void Update(float deltaTime);
	void Render(AssetManager* assetManager, float x, float y, int spriteWidth, int spriteHeight) const;
	void SetProperties(const std::string& textureId, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);


	int m_SpriteRow;
	int m_SpriteFrame;
	int m_AnimationSpeed;
	int m_FrameCount;
	std::string& m_TextureId;
	SDL_RendererFlip m_Flip;

};