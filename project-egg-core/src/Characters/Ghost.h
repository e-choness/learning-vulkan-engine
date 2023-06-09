#pragma once
#ifndef GHOST_H
#define GHOST_H
class Animation;
#include "Character.h"
#include "AssetManager.h"
#include "Animation.h"
#include "RigidBody.h"

class Ghost: public Character {
public:
	Ghost(Properties *properties);

	void Render();
	void Update(float deltaTime);
	void Clean();

	Animation* m_Animation;
	RigidBody* m_RigidBody;
};

#endif // !GHOST_H