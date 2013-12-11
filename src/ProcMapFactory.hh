#include "ProcMap.hh"

using namespace std

class ProcMapFactory {
private:
	static ProcMapFactory mPMapFactory = NULL;
	ProcMapFactory();
public:
	static ProcMapFactory getProcMapFactory();
	ProcMap createProcMap(MapFactoryOptions);
}
