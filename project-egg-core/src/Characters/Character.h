#ifndef CHARACTER_H
#define CHARACTER_H

#include"GameObject.h"

class Character : public GameObject{
public:
	Character(Properties *properties);

	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clean() = 0;

protected:
	const char* m_Name;

};

#endif // !CHARACTER_H
