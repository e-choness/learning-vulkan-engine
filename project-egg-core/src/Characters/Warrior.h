#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include "AssetManager.h"

class Warrior: public Character {
public:
	Warrior(Properties *properties);

	virtual void Render();
	virtual void Update(float deltaTime);
	virtual void Clean();
};

#endif // !WARRIOR_H
