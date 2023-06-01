#include "Ghost.h"

Ghost::Ghost(Properties* properties) : Character(properties)
{
	m_Row = 0;
	m_FrameCount = 8;
	m_Frame = 0;
	m_AnimationSpeed = 80;
	m_Name = "Ghost";
}

void Ghost::Render()
{
	AssetManager::GetInstance()->DrawFrame(m_TextureId, m_Transfrom->X, m_Transfrom->Y, m_Width, m_Height, m_Row, m_Frame);
}

void Ghost::Update(float deltaTime)
{
	m_Frame = (SDL_GetTicks() / m_AnimationSpeed) % m_FrameCount;
}

void Ghost::Clean()
{
	AssetManager::GetInstance()->CleanTexture();
}
