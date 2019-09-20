#include "MapLoader.h"

bool MapLoader::IsReady()
{
	return IsCreated;
}

void MapLoader::FillTiles(const string& FilePath)
{
	Texture texture;
	texture.loadFromFile(FilePath);
	while (Counter < MaxTileC)
	{
		while (Counter < Columns)
		{
			Sprite* s = new Sprite;
			s->setTextureRect(IntRect(Counter * TileWidth, Row * TileHeight, TileWidth, TileHeight));
			Tiles.emplace((Counter + 1), *s);
			Counter++;
		}
		Row++;
	}
}

MapLoader::MapLoader()
{
	FillTiles("maps/main.tmx");
	CreateMap();
}
