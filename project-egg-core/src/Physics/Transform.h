#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include<SDL.h>
#include"Vector2D.h"

class Transform {
public:
	Transform(float x = 0.0f, float y = 0.0f);
	void Log(const char* message);

	float X, Y;
private:
	inline void TranslateX(float x) { X += x; }
	inline void TranslateY(float y) { Y += y; }
	void Translate(Vector2D* v);
};

#endif // TRANSFORM_H