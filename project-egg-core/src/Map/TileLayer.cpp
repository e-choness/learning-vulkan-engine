#include "TileLayer.h"

TileLayer::TileLayer(int tileSize, int rowCount, int colCount, std::vector<std::vector<int>> tileMap, std::vector<Tileset> tilesets):
	m_Tilesets(tilesets),
	m_TileSize(tileSize), m_RowCount(rowCount), m_ColCount(colCount), m_TileMap(tileMap) 
{
	for (unsigned int i = 0; i < m_Tilesets.size(); i++) {
		AssetManager::GetInstance()->LoadTexture(m_Tilesets[i].Name, "assets/background/" + m_Tilesets[i].Source);
	}
}

void TileLayer::Render()
{
	for (unsigned int i = 0; i < m_RowCount; i++) {
		for (unsigned int j = 0; j < m_ColCount; j++) {
			int tileId = m_TileMap[i][j];
			
			// Tile id is 0 means there is nothing to draw, hence skip the index and tile id calculation.
			if (tileId == 0)
				continue;
			else {
				int index = 1;
				// Tilesets in lower layers, their starting id is not 0, and it needs calculation here.
				if (m_Tilesets.size() > 1) {
					// Calculating starting tile id of current tileset
					for (unsigned int k = 1; k < m_Tilesets.size(); k++) {
						if (tileId > m_Tilesets[k].FirstId && tileId < m_Tilesets[k].LastId) {
							tileId = tileId + m_Tilesets[k].TileCount - m_Tilesets[k].LastId;
							index = k;
							break;
						}
					}
				}
				Tileset tileset = m_Tilesets[index];
				int tileRow = tileId / tileset.ColCount;
				// Column's starting index is 0, so calculating tile columns needs to subtract 1.
				int tileCol = tileId - tileRow * tileset.ColCount - 1;

				// If this tile is one the last column
				if (tileId % tileset.ColCount == 0) {
					tileRow--;
					tileCol = tileset.ColCount - 1;
				}

				//XXX AssetManager::GetInstance()->DrawTile(tileset.Name, tileset.TileSize,static_cast<float> (j), static_cast<float> (i), (j * tileset.TileSize), (i * tileset.TileSize), tileRow, SDL_FLIP_NONE );
			}
		}
	}
}

void TileLayer::Update()
{
}
