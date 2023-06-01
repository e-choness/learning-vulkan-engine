#include "Vector2D.h"

Vector2D::Vector2D(int x, int y):X(x), Y(y)
{
}

void Vector2D::LogVector(const char* message)
{
	SDL_Log("%s (X, Y) = (%d, %d)\n", message, X, Y);
}
