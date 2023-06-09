#include "Vector2D.h"

Vector2D::Vector2D(float x, float y):X(x), Y(y)
{
}

void Vector2D::LogVector(const char* message)
{
	SDL_Log("%s (X, Y) = (%f, %f)\n", message, X, Y);
}
