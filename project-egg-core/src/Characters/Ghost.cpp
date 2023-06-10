#include "Ghost.h"

Ghost::Ghost(Properties* properties) : Character(properties)
{
	m_RigidBody = new RigidBody();
	m_Animation = new Animation();
	m_RigidBody->UnsetGravity();
	/*m_TextureId = "ghost-floating";
	m_Animation->SetProperties(m_TextureId, 0, 8, 80, SDL_FLIP_HORIZONTAL);*/
}

void Ghost::Render()
{
	m_Animation->Render(m_Transfrom->X, m_Transfrom->Y, m_Width, m_Height);
}

void Ghost::Update(float deltaTime)
{	
	
	m_RigidBody->Update(deltaTime);
	
	Floating();
	Moving();

	m_Transfrom->Translate(m_RigidBody->GetPosition());
	m_Animation->Update(deltaTime);
}

void Ghost::Clean()
{
	AssetManager::GetInstance()->CleanTexture();
}

void Ghost::Floating() {
	m_TextureId = "ghost-floating";

	m_Animation->SetProperties(m_TextureId, 0, 8, 100, SDL_FLIP_HORIZONTAL);
	m_RigidBody->UnsetForce();
}

void Ghost::Moving() {
	m_TextureId = "ghost-running";
	
	if (InputSystem::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {		
		m_Animation->SetProperties(m_TextureId, 0, 6, 50);
		m_RigidBody->ApplyForceX(-20.0f);
		
	}
	if (InputSystem::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {		
		m_Animation->SetProperties(m_TextureId, 0, 6, 50, SDL_FLIP_HORIZONTAL);
		m_RigidBody->ApplyForceX(20.0f);
	}
	if (InputSystem::GetInstance()->GetKeyDown(SDL_SCANCODE_W)) {
		m_RigidBody->ApplyForceY(-10.0f);
	}
	if (InputSystem::GetInstance()->GetKeyDown(SDL_SCANCODE_S)) {
		m_RigidBody->ApplyForceY(10.0f);
	}
}
