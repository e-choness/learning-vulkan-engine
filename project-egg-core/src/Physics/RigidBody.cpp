#include "RigidBody.h"

RigidBody::RigidBody():m_Mass(UNI_MASS), m_Gravity(GRAVITY)
{
}

void RigidBody::Update(float deltaTime)
{
	m_Accelaration.X = (m_Force.X + m_Friction.X) / m_Mass;
	m_Accelaration.Y = m_Gravity + m_Force.Y / m_Mass;
	m_Velocity = m_Accelaration * deltaTime;
	m_Position = m_Velocity * deltaTime;
}