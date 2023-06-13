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

bool MapParser::Parse(std::string id, std::string source)
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
	tinyxml2::XMLElement* data = nullptr;
	for (tinyxml2::XMLElement* e = xmlLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("data")) {
			data = e;
			break;
		}
	}

	if (data != nullptr) {
		std::string matrix(data->GetText());
		std::istringstream iss(matrix);
		std::string id;

		TileMap tilemap(rowCount, std::vector<int>(colCount, 0));

		for (int row = 0; row < rowCount; row++) {
			for (int col = 0; col < colCount; col++) {
				std::getline(iss, id, ',');
			}
		}
	}
	
	return nullptr;
}
