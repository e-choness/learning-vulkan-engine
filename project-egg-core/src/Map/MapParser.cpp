#include "MapParser.h"
#include "TileLayer.h"

MapParser* MapParser::s_Instance = nullptr;

MapParser::MapParser() {

}

MapParser* MapParser::GetInstance()
{
	return s_Instance = (s_Instance != nullptr) ? s_Instance : new MapParser();
}

bool MapParser::Load()
{
	return Parse("MAP", "../night-forest.tmx");
}

void MapParser::Clean()
{
	std::map<std::string, GameMap*>::iterator it;
	for (it = m_MapDictionary.begin(); it != m_MapDictionary.end(); it++) {
		it->second = nullptr;
	}
	m_MapDictionary.clear();
}

GameMap* MapParser::GetMap(std::string id)
{
	return m_MapDictionary[id];
}

bool MapParser::Parse(std::string id, std::string source)
{
	tinyxml2::XMLDocument xml;
	xml.LoadFile(source.c_str());

	if (xml.Error()) {
		SDL_Log("Failed to load texture: %s, %s", source.c_str(), SDL_GetError());
		return false;
	}

	tinyxml2::XMLElement* root = xml.RootElement();
	int rowCount = 0, colCount = 0, tileSize = 0;

	root->QueryIntAttribute("width", &colCount);
	root->QueryIntAttribute("height", &rowCount);
	root->QueryIntAttribute("tilewidth", &tileSize);

	// Parse Tilesets.
	std::vector<Tileset> tilesets;
	for (tinyxml2::XMLElement* element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement()) {
		if (element->Value() == std::string("tileset")) {
			tilesets.push_back(ParseTileset(element));
		}
	}

	// Parse game map.
	GameMap* gameMap = new GameMap();
	for (tinyxml2::XMLElement* element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement()) {
		if (element->Value() == std::string("layer")) {
			TileLayer* tilelayer = ParseTileLayer(element, tilesets, tileSize, rowCount, colCount);
			gameMap->m_MapLayers.push_back(tilelayer);
		}
	}

	m_MapDictionary[id] = gameMap;
	return true;
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

TileLayer* MapParser::ParseTileLayer(tinyxml2::XMLElement* xmlLayer, std::vector<Tileset> tilesets, int tileSize, int rowCount, int colCount)
{
	tinyxml2::XMLElement* data = nullptr;
	for (tinyxml2::XMLElement* e = xmlLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("data")) {
			data = e;
			break;
		}
	}

	typename std::vector<std::vector<int>> tilemap(rowCount, std::vector<int>(colCount, 0));

	if (data != nullptr) {
		std::string matrix(data->GetText());
		std::istringstream iss(matrix);
		std::string id;

		for (int row = 0; row < rowCount; row++) {
			for (int col = 0; col < colCount; col++) {
				std::getline(iss, id, ',');
				std::stringstream convertor(id);
				convertor >> tilemap[row][col];
				if (!iss.good()) {
					break;
				}
			}
		}
	}
	
	return (new TileLayer(tileSize, rowCount, colCount, tilemap, tilesets));
}
