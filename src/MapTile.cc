#include "MapTile.hh"

MapTile::MapTile() : mElevation(0)
{
}

MapTile::~MapTile() {
}

void MapTile::setTerrainWeight( Terrain terrain, int weight ) {
	string derivedClass = typeid(terrain).name();
	mTerrainWeights.insert(pair<string,int>(derivedClass,weight));
}

void MapTile::removeTerrainWeight( Terrain terrain ) {
	string derivedClass = typeid(terrain).name();
	map<string,int>::iterator it;
	it = mTerrainWeights.find(derivedClass);
	mTerrainWeights.erase( it, mTerrainWeights.end() );
}

void MapTile::setElevation( Elevation elevation )
{
	mElevation = elevation;
}

map<string,int> MapTile::getTerrainWeights()
{
	return mTerrainWeights;
}

Elevation MapTile::getElevation()
{
	return mElevation;
}
