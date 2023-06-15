#pragma once

#include <vector>
#include "Layer.h"


class GameMap {
public:
	void Render();
	void Update();
	inline std::vector<Layer*> GetLayers() { return m_MapLayers; }

private:
	friend class MapParser;
	std::vector<Layer*> m_MapLayers;
};
