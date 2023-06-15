#pragma once

const int TARGET_FPS = 60;
const float TARGET_FRAMERATE = 1.5f;

#include <SDL.h>

class Timer {
public:
	void Tick();
	float GetDeltaTime() { return m_DeltaTime;}
	static Timer* GetInstance() { 
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Timer(); }

private:
	Timer();
	static Timer* s_Instance;
	float m_DeltaTime;
	float m_LastTime;
};