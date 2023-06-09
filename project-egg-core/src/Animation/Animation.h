#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>
#include "AssetManager.h"

class Animation {
public:
	Animation();

	void Update(float deltaTime);
	void Render(int x, int y, int spriteWidth, int spriteHeight);
	void SetProperties(const char* textureId, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);


	int m_SpriteRow;
	int m_SpriteFrame;
	int m_AnimationSpeed;
	int m_FrameCount;
	const char* m_TextureId;
	SDL_RendererFlip m_Flip;
};

#endif // !ANIMATION_H