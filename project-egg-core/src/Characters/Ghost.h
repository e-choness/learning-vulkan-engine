#ifndef GHOST_H
#define GHOST_H

#include "Character.h"
#include "AssetManager.h"
#include "SDL.h"

class Ghost: public Character {
public:
	Ghost(Properties *properties);

	void Render();
	void Update(float deltaTime);
	void Clean();
private:
	int m_Row;
	int m_Frame;
	int m_FrameCount;
	int m_AnimationSpeed;
};

#endif // !GHOST_H
