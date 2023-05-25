#pragma once
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include<SDL.h>

class Vector2D {
public:
	// 2D vector constructor
	Vector2D(float x = 0.0f, float y = 0.0f);

	// 2D vector addition operation
	inline Vector2D operator+(Vector2D& v2) const {
		return Vector2D(X + v2.X, Y + v2.Y);
	}

	// 2D vector subtraction operation
	inline Vector2D operator-(Vector2D& v2) const {
		return Vector2D(X - v2.X, Y - v2.Y);
	}

	// 2D vector cross product operation
	// If v2 is on the left hand side of v1, the cross product is negative;
	// If v2 is on the right hand side of v1, the cross product is positive;
	// If v2 is parallel to v1, the cross product is 0;
	// Useful when calculating sin.
	inline float operator*(Vector2D v2) const {
		return (X * v2.Y - Y * v2.X);
	}

	// 2D vector dot product operation
	// If v2 is diagonal to v1, the dot product is 0.
	// Useful when calculating cos.
	inline float Dot(Vector2D& v2) const {
		return (X * v2.X + Y * v2.Y);
	}
	
	void LogVector(const char* message);

	// The x and y values on the cordinator
	float X, Y;
};

#endif // VECTOR2D_H