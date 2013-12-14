#ifndef __BASIC_TERRAIN_PROB_OPTION__HH__
#define __BASIC_TERRAIN_PROB_OPTION__HH__

#include <map>
#include <string>
#include "ProcMap.hh"
#include "ProcMapTerrainOption.hh"

using namespace std;

class BasicTerrainProbOption : public ProcMapTerrainOption {
private:
	map<string,int> mProbabilities;
public:
	BasicTerrainProbOption();
	~BasicTerrainProbOption();
	virtual void runOption(ProcMap*);
	void setProbability(string, int);
};

#endif
