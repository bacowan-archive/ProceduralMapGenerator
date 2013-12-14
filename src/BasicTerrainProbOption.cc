#include "BasicTerrainProbOption.hh"

BasicTerrainProbOption::BasicTerrainProbOption() {
	mProbabilities = map<string,int>();
}

BasicTerrainProbOption::~BasicTerrainProbOption(){
}

void
BasicTerrainProbOption::runOption(ProcMap* map) {
	
}

void
BasicTerrainProbOption::setProbability(string terrainName, int weight) {
	mProbabilities.insert(pair<string,int>(terrainName,weight));
}
