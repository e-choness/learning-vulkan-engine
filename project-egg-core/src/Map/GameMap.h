#pragma once
#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "Layer.h"


class GameMap {
public:
	void Render();
	void Update();
	inline std::vector<Layer*> GetLayers() { return m_MapLayers; }
private:
	std::vector<Layer*> m_MapLayers;
};

#endif // !GAMEMAP_H
