#pragma once

#include<SDL.h>
#include<string>
#include"Vector2D.h"

class Transform {
public:
	Transform(float x = 0.0f, float y = 0.0f);
	void Log(std::string message);
	void Translate(Vector2D v);
	void TranslateX(float x) { X += x; }
	void TranslateY(float y) { Y += y; }

	float X, Y;
};