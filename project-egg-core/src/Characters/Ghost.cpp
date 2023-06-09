#include "Ghost.h"

Ghost::Ghost(Properties* properties) : Character(properties)
{
	m_Animation = new Animation();
	m_Animation->SetProperties(m_TextureId, 0, 8, 80, SDL_FLIP_HORIZONTAL);
}

void Ghost::Render()
{
	m_Animation->Render(m_Transfrom->X, m_Transfrom->Y, m_Width, m_Height);
}

void Ghost::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
}

void Ghost::Clean()
{
	AssetManager::GetInstance()->CleanTexture();
}
