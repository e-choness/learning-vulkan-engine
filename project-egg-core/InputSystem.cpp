#include "InputSystem.h"

InputSystem::InputSystem()
{
	quit = false;
	keyboardState = SDL_GetKeyboardState(NULL);
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);
}

InputSystem::~InputSystem()
{
}

void InputSystem::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			break;
		case SDL_KEYUP:
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		case SDL_MOUSEMOTION:
			mouseX = event.motion.x;
			mouseY = event.motion.y;
			break;
		default:
			break;
		}
	}

	keyboardState = SDL_GetKeyboardState(NULL);
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);
}

bool InputSystem::quitRequested()
{
	return quit;
}

bool InputSystem::keyPressed(SDL_Keycode keycode)
{
	if (keyboardState[keycode]) {
		return true;
	}
	return false;
}

bool InputSystem::keyReleased(SDL_Keycode keycode)
{
	if (!keyboardState[keycode]) {
		return true;
	}
	return false;
}

bool InputSystem::mouseButtonPressed(int button)
{
	if (mouseState && SDL_BUTTON(button)) {
		return true;
	}
	return false;
}

bool InputSystem::mouseButtonReleased(int button)
{
	if (!(mouseState && SDL_BUTTON(button))) {
		return true;
	}
	return false;
}

int InputSystem::getMouseX()
{
	return mouseX;
}

int InputSystem::getMouseY()
{
	return mouseY;
}

