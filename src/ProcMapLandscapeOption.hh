#ifndef __PROC_MAP_LANDSCAPE_OPTION__HH__
#define __PROC_MAP_LANDSCAPE_OPTION__HH__

#include "ProcMapOption.hh"

using namespace std;

class ProcMapLandscapeOption : public ProcMapOption {
public:
	virtual void runOption(ProcMap*) = 0;
};

#endif
