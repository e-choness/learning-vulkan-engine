#pragma once

#define GRAVITY 1.0f
#define UNI_MASS 9.0f

#define UPWARD -1.0f
#define DOWNWARD 1.0f
#define FORWARD -1.0f
#define BACKWARD 1.0f

#include "Vector2D.h"

class RigidBody {
public:
	RigidBody();

    void SetForce(float mass) { m_Mass = mass; }
    void SetGravity(float gravity) { m_Gravity = gravity; }
    void UnsetGravity() { m_Gravity = 0.0f; }

    void ApplyForce(Vector2D force) { m_Force = force; }
    void ApplyForceX(float x) { m_Force.X = x; }
    void ApplyForceY(float y) { m_Force.Y = y; }
    void UnsetForce() { m_Force = Vector2D(0.0f, 0.0f); }

    void ApplyFriction(Vector2D friction) { m_Friction = friction; }
    void UnsetFriction() { m_Friction = Vector2D(0.0f, 0.0f); }

    float GetMass() { return m_Mass; }
    Vector2D GetPosition() { return m_Position; }
    Vector2D GetVelocity() { return m_Velocity; }
    Vector2D GetAccelaration() { return m_Accelaration; }
    Vector2D GetForce() { return m_Force; }
    Vector2D GetGravity() { return m_Gravity; }

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
