#ifndef __PROC_MAP_SURROUNDINGS_OPTION__HH__
#define __PROC_MAP_SURROUNDINGS_OPTION__HH__

#include "ProcMapOption.hh"

using namespace std;

class ProcMapSurroundingsOption : public ProcMapOption {
public:
	virtual void runOption(ProcMap*) = 0;
};

#endif
