#include "Timer.h"

Timer::Timer():m_DeltaTime(0.0f), m_LastTime(0.0f){

}

void Timer::Tick()
{
	m_DeltaTime = ( static_cast<float>(SDL_GetTicks()) - m_LastTime) * (TARGET_FPS / 1000.0f);

	if (m_DeltaTime > TARGET_FRAMERATE) {
		m_DeltaTime = TARGET_FRAMERATE;
	}

	m_LastTime = static_cast<float>(SDL_GetTicks());
}
