#ifndef __PROC_MAP__HH__
#define __PROC_MAP__HH__

#include <vector>
#include "MapTile.hh"

using namespace std;

class ProcMap {
private:
	vector< vector<MapTile> > mMapTiles;
public:
	ProcMap(int, int);
	~ProcMap();
	vector< vector<MapTile> > getMapTiles();
	void setTile(int, int, MapTile);
	MapTile getTile(int, int);
};

#endif
