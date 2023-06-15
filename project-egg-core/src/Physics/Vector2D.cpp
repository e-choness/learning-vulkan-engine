#include "Vector2D.h"

Vector2D::Vector2D(float x, float y):X(x), Y(y)
{
}

void Vector2D::LogVector(std::string message)
{
	SDL_Log("%s (X, Y) = (%f, %f)\n", message.c_str(), X, Y);
}
