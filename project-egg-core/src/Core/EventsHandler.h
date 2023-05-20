#pragma once
#ifndef EVENTSHANDLER_H
#define EVENTSHANDLER_H

#include<SDL.h>

class EventsHandler
{
public:
	EventsHandler();
	inline SDL_Event* GetEvent() { return m_Event; }
	
	inline void SetEvent(SDL_Event* event) { m_Event = event; }

	inline bool IsRunning() { return m_IsRunning; }
	void QuitEvent();

private:
	SDL_Event* m_Event;
	bool m_IsRunning;
};

#endif // EVENTSHANDLER_H

