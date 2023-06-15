#include "Transform.h"

Transform::Transform(float x, float y):X(x),Y(y)
{
}

void Transform::Log(std::string message)
{
	SDL_Log("%s (X, Y) = (%f, %f)\n", message.c_str(), X, Y);
}

void Transform::Translate(Vector2D v)
{
	X += v.X;
	Y += v.Y;
}
