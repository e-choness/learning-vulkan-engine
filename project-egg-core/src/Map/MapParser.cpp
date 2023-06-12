#include "MapParser.h"

MapParser* MapParser::s_Instance = nullptr;

MapParser::MapParser() {

}

MapParser* MapParser::GetInstance()
{
	return s_Instance = (s_Instance != nullptr) ? s_Instance : new MapParser();
}

bool MapParser::Load()
{
	return Parse("level1", "assets/background/night-forest.tmx");
}

void MapParser::Clean()
{
}

GameMap* MapParser::GetMap()
{
	return nullptr;
}

bool MapParser::Parse(const char* id, const char* source)
{
	
	return false;
}

Tileset MapParser::ParseTileset(tinyxml2::XMLElement* xmlTileset)
{
	Tileset tileset = {};
	tileset.Name = xmlTileset->Attribute("name");
	xmlTileset->QueryIntAttribute("firstgid",&tileset.FirstId);

	xmlTileset->QueryIntAttribute("tilecount", &tileset.TileCount);
	tileset.LastId = (tileset.FirstId + tileset.TileCount) - 1;

	xmlTileset->QueryIntAttribute("columns", &tileset.ColCount);
	tileset.RowCount = tileset.TileCount / tileset.ColCount;

	xmlTileset->QueryIntAttribute("tilewidth", &tileset.TileSize);

	tinyxml2::XMLElement* image = xmlTileset->FirstChildElement();
	tileset.Source = image->Attribute("source");

	return tileset;
}

TileLayer* MapParser::ParseTileLayer(tinyxml2::XMLElement* xmlLayer, TilesetList tilesets, int tileSize, int rowCount, int colCount)
{
	return nullptr;
}
