#pragma once
#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <map>
#include "GameMap.h"
#include "TileLayer.h"
#include "tinyxml2.h"

class MapParser
{
public:
	static MapParser* GetInstance();

	bool Load();
	void Clean();

	GameMap* GetMap();
	bool Parse(const char* id, const char* source);

	Tileset ParseTileset(tinyxml2::XMLElement* xmlTileset);

	TileLayer* ParseTileLayer(tinyxml2::XMLElement* xmlLayer, TilesetList tilesets, int tileSize, int rowCount, int colCount);

private:
	MapParser();
	static MapParser* s_Instance;
	std::map<const char*, GameMap*> m_MapDictionary;
	
};


#endif // !MAPPARSER_H