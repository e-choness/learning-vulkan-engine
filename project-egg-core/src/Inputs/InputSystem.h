#pragma once

#include <SDL.h>
#include "Engine.h"

class InputSystem
{
public:
	static InputSystem* GetInstance() {
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new InputSystem();
	}

	// Listening to game events.
	void Listen();

	// Return true if a key is pressed.
	bool GetKeyDown(SDL_Scancode keyCode);

	// Update keyboard and mouse states by listening to poll event.
	void Update();

	// Return true if any mouse button is pressed.
	bool mouseButtonPressed(int button);

	// Return true if any mouse button is released.
	bool mouseButtonReleased(int button);

	// Get mouse position on X coordinate
	int getMouseX();

	// Get mouse position on Y coordinate
	int getMouseY();

private:
	// Private constructor so that only one instance is running at a time, nothing else can create it accidentally.
	InputSystem();	

	// Handle any is released.
	void KeyReleased();

	// Handle any key is pressed.
	void KeyPressed();

	// One and only static instance.
	static InputSystem* s_Instance;

	// Keyboard State 
	const Uint8* m_KeyBoardState;

	// Mouse State
	int mouseState;

	// Mouse position on X coordinate
	int mouseX;

	// Mouse position on Y coordinate
	int mouseY;
};