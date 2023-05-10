#pragma once
#include<SDL.h>
class InputSystem
{
public:
	// Initiating Input System.
	InputSystem();
	// Deconstruct Input System instance.
	~InputSystem();

	// Update keyboard and mouse states by listening to poll event.
	void update();

	// Request quit signal.
	bool quitRequested();

	// Return true if any key is pressed.
	bool keyPressed(SDL_Keycode keycode);

	// Return true if any key is released.
	bool keyReleased(SDL_Keycode keycode);

	// Return true if any mouse button is pressed.
	bool mouseButtonPressed(int button);

	// Return true if any mouse button is released.
	bool mouseButtonReleased(int button);

	// Get mouse position on X coordinate
	int getMouseX();

	// Get mouse position on Y coordinate
	int getMouseY();

private:
	// A flag for quit signal
	bool quit;

	// Keyboard State 
	const Uint8* keyboardState;

	// Mouse State
	int mouseState;

	// Mouse position on X coordinate
	int mouseX;

	// Mouse position on Y coordinate
	int mouseY;
};

