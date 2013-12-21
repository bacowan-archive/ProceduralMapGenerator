#include "TestTerrain.hh"

TestTerrain::TestTerrain() : mBasicTerrain(), mRep() {
}

TestTerrain::TestTerrain(int x, int y) : mBasicTerrain(x,y), mRep() {
}

TestTerrain::~TestTerrain() {
}

int
TestTerrain::getSeeds() {
	return mBasicTerrain.getSeeds();
}

void
TestTerrain::setSeeds(int seeds) {
	mBasicTerrain.setSeeds(seeds);
}

int
TestTerrain::getWeight() {
	return mBasicTerrain.getWeight();
}

void
TestTerrain::setWeight(int weight) {
	mBasicTerrain.setWeight(weight);
}

string
TestTerrain::getStringRepresentation() {
	return mRep;
}

void
TestTerrain::setStringRepresentation(string rep) {
	mRep = rep;
}
