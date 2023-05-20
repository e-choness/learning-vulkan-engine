#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include<SDL.h>

class Engine
{
public:	
	static Engine* GetInstance();

	bool Init();
	bool Clean();
	void Quit();


	void Update(float deltaTime);
	void Render();
	void Events();

	inline bool isRunning();

protected:

private:
	Engine();
	bool m_IsRunning = true;
	static Engine* s_Instance;
};

#endif // ENGINE_H

