#pragma once

#include "SDL.h"

class IObject {	
	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clean() = 0;
};