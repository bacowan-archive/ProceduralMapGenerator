#ifndef __MAP_TILE__HH__
#define __MAP_TILE__HH__

#include <map>
#include <typeinfo>
#include <string>
#include "Terrain.hh"
#include "Elevation.hh"

using namespace std;

class MapTile {
private:
	map< string, int > mTerrainWeights; // terrain weightings
	Elevation mElevation;
public:
	MapTile();
	~MapTile();
	void setTerrainWeight( Terrain, int );
	void removeTerrainWeight( Terrain );
	void setElevation( Elevation );
	map< string, int > getTerrainWeights();
	Elevation getElevation();
};

#endif
