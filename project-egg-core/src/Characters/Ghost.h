#pragma once

#include "Character.h"
#include "AssetManager.h"
#include "Animation.h"
#include "RigidBody.h"
#include "InputSystem.h"

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