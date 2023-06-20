#include "GameObject.h"

GameObject::GameObject(RectProperties* rectProp, RenderProperties* renderProp, TextureProperties* textureProp) :
 	m_RectProperties(rectProp), m_RenderProperties(renderProp),m_TextureProperties(textureProp)
{
	m_Transfrom = new Transform(rectProp->X, rectProp->Y);
};