#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"IObject.h"
#include"Transform.h"
#include"SDL.h"
#include<string>

struct Properties {
public:
	Properties(std::string textureId, float x, float y, int width, int height,  SDL_RendererFlip flip = SDL_FLIP_NONE):
		X(x), Y(y), Width(width), Height(height), TextureId(textureId), Flip(flip) {
	}
public:
	float X, Y;
	int Width, Height;
	std::string TextureId;
	SDL_RendererFlip Flip;
};

class GameObject : public IObject {
public:
	GameObject(Properties* properties);

	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clean() = 0;

protected:
	Transform* m_Transfrom;
	int m_Width, m_Height;
	std::string m_TextureId;
	SDL_RendererFlip m_Flip;
};

#endif // !GAMEOBJECT_H