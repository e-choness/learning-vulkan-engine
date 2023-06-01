#ifndef IOBJECT_H
#define IOBJECT_H

#include "SDL.h"

class IObject {	
	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clean() = 0;
};

#endif // !IOBJECT_H
