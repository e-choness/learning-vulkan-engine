#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include"GameObject.h"
#include<string>

class Character : public GameObject{
public:
	Character(Properties *properties);

	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clean() = 0;

protected:
	std::string m_Name;
};

#endif // !CHARACTER_H
