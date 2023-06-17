#pragma once

#include "IObject.h"
#include "Graphics/RenderProperties.h"
#include "Graphics/AssetProperties.h"
#include "Physics/Transform.h"
#include <SDL3/SDL.h>
#include <string>

//struct Properties {
//public:
//	Properties(std::string textureId, float x, float y, float width, float height,  SDL_RendererFlip flip = SDL_FLIP_NONE):
//		X(x), Y(y), Width(width), Height(height), TextureId(std::move(textureId)), Flip(flip) {
//	}
//public:
//	float X, Y;
//    float Width, Height;
//	std::string TextureId;
//	SDL_RendererFlip Flip;
//};

class GameObject : public IObject {
public:
	explicit GameObject(RectProperties* rectProp, RenderProperties* renderProp, TextureProperties* textureProp);

	void Render() override = 0;
	void Update(float deltaTime) override = 0;
	void Clean() override = 0;

protected:
	Transform* m_Transfrom;
    RectProperties* m_RectProperties;
	RenderProperties* m_RenderProperties;
    TextureProperties* m_TextureProperties;
};