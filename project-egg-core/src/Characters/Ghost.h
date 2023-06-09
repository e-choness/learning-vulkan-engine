#pragma once
#ifndef GHOST_H
#define GHOST_H

#include "Character.h"
#include "AssetManager.h"

class Animation;

class Ghost: public Character {
public:
	Ghost(Properties *properties);

	void Render();
	void Update(float deltaTime);
	void Clean();

	Animation* m_Animation;
};
#include "Animation.h"
#endif // !GHOST_H