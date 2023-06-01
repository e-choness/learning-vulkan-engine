#include "Transform.h"

Transform::Transform(int x, int y):X(x),Y(y)
{
}

void Transform::Log(const char* message)
{
	SDL_Log("%s (X, Y) = (%d, %d)\n", message, X, Y);
}

void Transform::Translate(Vector2D* v)
{
	X += v->X;
	Y += v->Y;
}
