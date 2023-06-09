#pragma once
#ifndef GHOST_H
#define GHOST_H
class Animation;
#include "Character.h"
#include "AssetManager.h"
#include "Animation.h"

class Ghost: public Character {
public:
	Ghost(Properties *properties);

	void Render();
	void Update(float deltaTime);
	void Clean();

	Animation* m_Animation;
};

#endif // !GHOST_H