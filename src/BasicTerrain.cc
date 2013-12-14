#include "BasicTerrain.hh"

BasicTerrain::BasicTerrain(){
	BasicTerrain(0,0);
}

BasicTerrain::BasicTerrain(int numberOfSeeds, int weight) : mSeeds(numberOfSeeds), mWeight(weight) {
}

BasicTerrain::~BasicTerrain() {
}

int
BasicTerrain::getSeeds() {
	return mSeeds;
}

void
BasicTerrain::setSeeds(int numberOfSeeds) {
	mSeeds = numberOfSeeds;
}

int
BasicTerrain::getWeight() {
	return mWeight;
}

void
BasicTerrain::setWeight(int weight) {
	mWeight = weight;
}
