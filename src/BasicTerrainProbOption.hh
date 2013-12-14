#ifndef __BASIC_TERRAIN_PROB_OPTION__HH__
#define __BASIC_TERRAIN_PROB_OPTION__HH__

#include <utility>
#include <stdexcept>
#include <string>
#include <map>
#include <vector>
#include <stdlib.h>
#include "ProcMap.hh"
#include "ProcMapTerrainOption.hh"
#include "BasicTerrain.hh"

using namespace std;

class BasicTerrainProbOption : public ProcMapTerrainOption {
private:
	map<string,BasicTerrain> mProbabilities;
	bool spread(int, int, ProcMap*);
	bool consume(MapTile, MapTile);
public:
	BasicTerrainProbOption();
	~BasicTerrainProbOption();
	virtual void runOption(ProcMap*, int);
	void setProbability(BasicTerrain);
};

#endif
