#include "GameObject.h"

GameObject::GameObject(Properties* properties) :
	m_TextureId(properties->TextureId),
	m_Width(properties->Width),
	m_Height(properties->Height),
	m_Flip(properties->Flip) 
{
	m_Transfrom = new Transform(properties->X, properties->Y);
};