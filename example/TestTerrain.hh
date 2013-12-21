#ifndef __TEST_TERRAIN__HH__
#define __TEST_TERRAIN__HH__

#include "BasicTerrain.hh"

using namespace std;

class TestTerrain : public Terrain {
private:
	BasicTerrain mBasicTerrain;
	string mRep;
public:
	TestTerrain();
	TestTerrain(int, int);
	~TestTerrain();
	int getSeeds();
	void setSeeds(int);
	int getWeight();
	void setWeight(int);
	string getStringRepresentation();
	void setStringRepresentation(string);

#endif
