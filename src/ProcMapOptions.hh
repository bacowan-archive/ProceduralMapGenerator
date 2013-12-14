#ifndef __PROC_MAP_OPTIONS__HH__
#define __PROC_MAP_OPTIONS__HH__

#include <set>
#include "ProcMap.hh"
#include "ProcMapOption.hh"
#include "ProcMapTerrainOption.hh"
#include "ProcMapLandscapeOption.hh"
#include "ProcMapHeightOption.hh"
#include "ProcMapSurroundingsOption.hh"

using namespace std;

class ProcMapOptions {
private:
	set<ProcMapTerrainOption*> mTerrainOptions;
	set<ProcMapSurroundingsOption*> mSurroundingsOptions;
	set<ProcMapHeightOption*> mHeightOptions;
	set<ProcMapLandscapeOption*> mLandscapeOptions;
	int mXSize;
	int mYSize;
	void runOptionSet(set<ProcMapOption*>, ProcMap*);
public:
	ProcMapOptions();
	ProcMapOptions(int, int);
	~ProcMapOptions();
	void addTerrainOption(ProcMapTerrainOption*);
	void addSurroundingsOption(ProcMapSurroundingsOption*);
	void addHeightOption(ProcMapHeightOption*);
	void addLandscapeOption(ProcMapLandscapeOption*);
	void setSize(int, int);
	ProcMap runOptions();
};

#endif
