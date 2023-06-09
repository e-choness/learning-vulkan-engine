#pragma once
#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#define GRAVITY 1.0f
#define UNI_MASS 9.0f

#include "Vector2D.h"

class RigidBody {
public:
	RigidBody();

	inline void SetForce(float mass) { m_Mass = mass; }
	inline void SetGravity(float gravity) { m_Gravity = gravity; }
	
	inline void ApplyForce(Vector2D force) { m_Force = force; }
	inline void ApplyForceX(float x) { m_Force.X = x; }
	inline void ApplyForceY(float y) { m_Force.Y = y; }
	inline void UnsetForce() { m_Force.X = 0.0f; m_Force.Y = 0.0f; }

	inline void ApplyFriction(Vector2D friction) { m_Friction = friction; }
	inline void UnsetFriction() { m_Friction.X = 0.0f; m_Friction.Y = 0.0f; }

	inline float GetMass() { return m_Mass; }
	inline Vector2D& GetPosition() { return m_Position; }
	inline Vector2D& GetVelocity() { return m_Velocity; }
	inline Vector2D& GetAccelaration() { return m_Accelaration; }

	void Update(float deltaTime);
	
private:
	float m_Mass;
	float m_Gravity;

	Vector2D m_Force;
	Vector2D m_Friction;

	Vector2D m_Position;
	Vector2D m_Velocity;
	Vector2D m_Accelaration;
};

#endif // !RIGIDBODY_H
