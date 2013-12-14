#ifndef __PROC_MAP_FACTORY__HH__
#define __PROC_MAP_FACTORY__HH__

#include "ProcMap.hh"
#include "ProcMapOptions.hh"

using namespace std;

class ProcMapFactory {
private:
	static ProcMapFactory *mPMapFactory;
	ProcMapFactory();
public:
	static ProcMapFactory getProcMapFactory();
	ProcMap createProcMap(ProcMapOptions);
};


#endif
