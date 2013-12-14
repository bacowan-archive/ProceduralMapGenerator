/**
 * liscence
 */

#include "ProcMapFactory.hh"

ProcMapFactory *ProcMapFactory::mPMapFactory = NULL;

ProcMapFactory::ProcMapFactory() {
}

/**
 * return the procmap factory
 * note: using the factory pattern in case I want to be able to extend to
 * different types of maps. Might refactor to just have the options.
 * @return this ProcMapFactory
 */
ProcMapFactory ProcMapFactory::getProcMapFactory() {
	if( mPMapFactory == NULL )
		mPMapFactory = new ProcMapFactory();
	return *mPMapFactory;
}

/**
 * Create the map.
 * @param options the options to generate the map with
 * @return the generated map
 */
ProcMap ProcMapFactory::createProcMap(ProcMapOptions options)
{
	return options.runOptions();
}
