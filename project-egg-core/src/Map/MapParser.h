#pragma once

#include "GameMap.h"
#include <tinyxml2.h>
#include <map>
#include <sstream>
#include <string>
#include <SDL.h>

class TileLayer;
struct Tileset;

class MapParser
{
public:
	static MapParser* GetInstance();

	bool Load();
	void Clean();

	GameMap* GetMap(std::string id);
	bool Parse(std::string id, std::string source);

	Tileset ParseTileset(tinyxml2::XMLElement* xmlTileset);

	TileLayer* ParseTileLayer(tinyxml2::XMLElement* xmlLayer, std::vector<Tileset> tilesets, int tileSize, int rowCount, int colCount);

private:
	MapParser();
	static MapParser* s_Instance;
	std::map<std::string, GameMap*> m_MapDictionary;
};