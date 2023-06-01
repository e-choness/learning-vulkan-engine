#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include<SDL.h>
#include"Vector2D.h"

class Transform {
public:
	Transform(int x = 0, int y = 0);
	void Log(const char* message);

	int X, Y;
private:
	inline void TranslateX(int x) { X += x; }
	inline void TranslateY(int y) { Y += y; }
	void Translate(Vector2D* v);
};

#endif // TRANSFORM_H