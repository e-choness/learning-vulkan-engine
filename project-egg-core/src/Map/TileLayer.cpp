#include "TileLayer.h"

TileLayer::TileLayer(int tileSize, int rowCount, int colCount, TileMap tileMap, TilesetList tilesets):
	m_Tilesets(tilesets),
	m_TileSize(tileSize), m_RowCount(rowCount), m_ColCount(colCount), m_TileMap(tileMap) 
{
}

void TileLayer::Render()
{
}

void TileLayer::Update()
{
}
