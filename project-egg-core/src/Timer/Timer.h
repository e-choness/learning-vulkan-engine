#pragma once

const int TARGET_FPS = 60;
const float TARGET_FRAMERATE = 1.5f;

#include <SDL.h>

class Timer {
public:
    Timer();
	void Tick();
	[[nodiscard]] float GetDeltaTime() const { return m_DeltaTime;}

private:
	float m_DeltaTime;
	float m_LastTime;
};