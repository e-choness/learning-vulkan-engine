#pragma once

#include "Character.h"
#include "Graphics/AssetManager.h"
#include "Animation/Animation.h"
#include "Physics/RigidBody.h"
#include "Inputs/InputSystem.h"

class Animation;

class Ghost: public Character {
public:
	Ghost(Properties *properties);

	void Render();
	void Update(float deltaTime);
	void Clean();

	void Moving();
	void Floating();

	Animation* m_Animation;
	RigidBody* m_RigidBody;
};