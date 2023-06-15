#include "InputSystem.h"

InputSystem* InputSystem::s_Instance = nullptr;

InputSystem::InputSystem()
{
	m_KeyBoardState = SDL_GetKeyboardState(nullptr);
}

void InputSystem::Listen()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_EVENT_QUIT: Engine::GetInstance()->Quit(); break;
		case SDL_EVENT_KEY_DOWN: KeyPressed(); break;
		case SDL_EVENT_KEY_UP: KeyReleased(); break;
		default:
			break;
		}
	}
}

bool InputSystem::GetKeyDown(SDL_Scancode keyCode)
{
	return (m_KeyBoardState[keyCode] == 1);
}

void InputSystem::Update()
{
	if (GetKeyDown(SDL_SCANCODE_A)) {
		SDL_Log("Key A pressed.");
	}
}

void InputSystem::KeyPressed()
{
	m_KeyBoardState = SDL_GetKeyboardState(nullptr);
}

void InputSystem::KeyReleased()
{
	m_KeyBoardState = SDL_GetKeyboardState(nullptr);
}

bool InputSystem::mouseButtonPressed(int button)
{
	return (mouseState && SDL_BUTTON(button));
}

bool InputSystem::mouseButtonReleased(int button)
{
	return !(mouseState && SDL_BUTTON(button));
}

int InputSystem::getMouseX()
{
	return mouseX;
}

int InputSystem::getMouseY()
{
	return mouseY;
}

