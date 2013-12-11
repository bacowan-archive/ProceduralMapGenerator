/**
 * liscence
 */

 #include "ProcMapFactory.hh"

 ProcMapFactory::ProcMapFactory() {
 }

 ProcMapFactory::getProcMapFactory() {
 	if( mPMapFactory == NULL )
		mPMapFactory = new ProcMapFactory();
	return mPMapFactory;
}

ProcMapFactory::createProcMap()
