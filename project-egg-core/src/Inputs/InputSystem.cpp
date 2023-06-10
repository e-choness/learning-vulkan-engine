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
		case SDL_QUIT: Engine::GetInstance()->Quit(); break;
		case SDL_KEYDOWN: keyPressed(); break;
		case SDL_KEYUP: keyReleased(); break;
		default:
			break;
		}
	}
}

bool InputSystem::GetKeyDown(SDL_Scancode keyCode)
{
	return (m_KeyBoardState[keyCode] == 1);
}

void InputSystem::update()
{
}

void InputSystem::keyPressed()
{
	m_KeyBoardState = SDL_GetKeyboardState(nullptr);
}

void InputSystem::keyReleased()
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

