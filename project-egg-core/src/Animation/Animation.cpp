#include "Animation.h"

Animation::Animation()
	: m_SpriteRow(0), m_SpriteFrame(0), m_AnimationSpeed(0), m_FrameCount(0), m_TextureId("")
{
}

void Animation::Update(float deltaTime)
{
	m_SpriteFrame = (SDL_GetTicks() / m_AnimationSpeed) % m_FrameCount;
}

void Animation::Render(AssetManager* assetManager, float x, float y, int spriteWidth, int spriteHeight)
{
    assetManager->DrawFrame(m_TextureId, x, y, spriteWidth, spriteHeight, m_SpriteRow, m_SpriteFrame, m_Flip);
}

void Animation::SetProperties(const std::string& textureId, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip)
{
	m_TextureId = textureId;
	m_SpriteRow = spriteRow;
	m_FrameCount = frameCount;
	m_AnimationSpeed = animationSpeed;
	m_Flip = flip;
}