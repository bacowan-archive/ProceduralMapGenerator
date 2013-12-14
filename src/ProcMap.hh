#ifndef __PROC_MAP__HH__
#define __PROC_MAP__HH__

#include <vector>
#include <stdexcept>
#include "MapTile.hh"

using namespace std;

class ProcMap {
private:
	vector< vector<MapTile> > mMapTiles;
public:
	ProcMap(int, int);
	~ProcMap();
	vector< vector<MapTile> > getMapTiles();
	int getXSize();
	int getYSize();
	void setTile(int, int, MapTile);
	void setTerrainWeight(int, int, Terrain, int);
	MapTile getTile(int, int);
};

#endif
