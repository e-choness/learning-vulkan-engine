#pragma once

#include "Graphics/AssetManager.h"
#include "Layer.h"
#include <vector>
#include <string>

struct Tileset {
	int FirstId, LastId;
	int RowCount, ColCount;
	int TileCount, TileSize;
	std::string Name;
	std::string Source;
};

class TileLayer: public Layer{
public:
	TileLayer(int tileSize, int rowCount, int colCount, std::vector<std::vector<int>> tileMap, std::vector<Tileset> tilesets);

	virtual void Render();
	virtual void Update();
	inline std::vector<std::vector<int>> GetTilemap() { return m_TileMap; }

private:
	int m_TileSize;
	unsigned int m_RowCount, m_ColCount;

	std::vector<std::vector<int>> m_TileMap;
	std::vector<Tileset> m_Tilesets;
};