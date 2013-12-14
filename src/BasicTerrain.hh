#ifndef __BASIC_TERRAIN__HH__
#define __BASIC_TERRAIN__HH__

#include "Terrain.hh"

using namespace std;

class BasicTerrain : public Terrain {
private:
	int mSeeds;
	int mWeight;
public:
	BasicTerrain();
	BasicTerrain(int, int);
	~BasicTerrain();
	int getSeeds();
	void setSeeds(int);
	int getWeight();
	void setWeight(int);
};

#endif
