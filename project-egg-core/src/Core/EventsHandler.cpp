#include "EventsHandler.h"

EventsHandler::EventsHandler():m_Event(nullptr), m_IsRunning(true)
{
	m_Event = new SDL_Event();
}

void EventsHandler::QuitEvent()
{
	SDL_PollEvent(m_Event);
	switch (m_Event->type) {
	case SDL_EVENT_QUIT:
		m_IsRunning = false;
		break;
	default:
		break;
	};
}


