#pragma once

#include <SDL.h>
#include <string>
#include "Graphics/AssetManager.h"

class Animation {
public:
	Animation();

	void Update(float deltaTime);
	void Render(float x, float y, int spriteWidth, int spriteHeight);
	void SetProperties(std::string textureId, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);


	int m_SpriteRow;
	int m_SpriteFrame;
	int m_AnimationSpeed;
	int m_FrameCount;
	std::string m_TextureId;
	SDL_RendererFlip m_Flip;
};