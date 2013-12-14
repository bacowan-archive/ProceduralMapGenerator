#include "ProcMap.hh"

/**
 * create a blank map of specified size
 * @param x the x size
 * @param y the y size
 */
ProcMap::ProcMap(int x, int y)
{
	mMapTiles.resize(x);
	for(int i = 0; i < x; i++)
	{
		mMapTiles[i].resize(y);
	}
}

/**
 * Destructor
 */
ProcMap::~ProcMap() {
}

/**
 * Get all tiles in the map
 * @return all tiles in the map
 */
vector< vector<MapTile> > ProcMap::getMapTiles()
{
	return mMapTiles;
}

/**
 * Get a single tile in the map
 * @param x x coordinate of the tile to get
 * @param y y coordinate of the tile to get
 * @return the tile
 */
MapTile ProcMap::getTile(int x, int y)
{
	return mMapTiles[x][y];
}

/**
 * Set a tile in the map
 * @param x x coordinate of the new tile
 * @param y y coordinate of the new tile
 * @param newTile the new tile
 */
void ProcMap::setTile(int x, int y, MapTile newTile)
{
	mMapTiles[x][y] = newTile;
}
