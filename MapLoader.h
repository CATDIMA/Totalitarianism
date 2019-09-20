#pragma once
#include "tinyxml2.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <vector>
#include <map>
#include <string>

using namespace std;
using namespace sf;

class MapLoader
{
public:
	
	void Draw(RenderTarget& target);
	void ClearMap();

	bool IsReady();

	static MapLoader& GetMapLoader()
	{
		static MapLoader instance;
		return instance;
	}
private:
	vector<Sprite> Map;
	map<int, Texture> Tiles;

	bool IsLoaded = false;
	bool IsCreated = false;

	int Columns = 10;		//Все эти значения должны задавться из вне
	int Rows = 1;
	int Counter = 0;		//Кроме этого
	int Row = 0;
	int TileWidth = 0;
	int TileHeight = 0;
	int MaxTileC = 16;

	void FillTiles(const string& FilePath);
	void CreateMap();

	MapLoader();
};