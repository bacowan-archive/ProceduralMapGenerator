#ifndef __PROC_MAP_TERRAIN_OPTION__HH__
#define __PROC_MAP_TERRAIN_OPTION__HH__

using namespace std;

#include "ProcMapOption.hh"

class ProcMapTerrainOption : public ProcMapOption {
public:
	virtual void runOption(ProcMap*) = 0;
};

#endif
