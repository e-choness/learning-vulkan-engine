#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"IObject.h"
#include"Transform.h"
#include"SDL.h"

struct Properties {
public:
	Properties(float x, float y, int width, int height, const char* textureId, SDL_RendererFlip flip = SDL_FLIP_NONE):
		X(x), Y(y), Width(width), Height(height), TextureId(textureId), Flip(flip) {
	}
public:
	float X, Y;
	int Width, Height;
	const char* TextureId;
	SDL_RendererFlip Flip;
};

class GameObject : public IObject {
public:
	GameObject(Properties* properties) :
		m_TextureId(properties->TextureId),
		m_Width(properties->Width),
		m_Height(properties->Height),
		m_Flip(properties->Flip) {
		
		m_Transfrom = new Transform(properties->X, properties->Y);
	};

	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clean() = 0;

protected:
	Transform* m_Transfrom;
	int m_Width, m_Height;
	const char* m_TextureId;
	SDL_RendererFlip m_Flip;
};

#endif // !GAMEOBJECT_H