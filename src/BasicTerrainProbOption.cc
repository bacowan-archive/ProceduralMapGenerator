#include "BasicTerrainProbOption.hh"

BasicTerrainProbOption::BasicTerrainProbOption() : mProbabilities() {
}

BasicTerrainProbOption::~BasicTerrainProbOption(){
}

void
BasicTerrainProbOption::runOption(ProcMap* procMap, int seed) {
	vector< pair<int,int> > unseeded;
	bool done = false;
	
	// keep track of what squares have not been seeded, for efficiency
	for(int i = 0; i < procMap->getXSize(); i++)
	{
		for(int j = 0; j < procMap->getYSize(); j++)
		{
			unseeded.push_back(make_pair(i,j));
		}
	}

	srand(seed);
	
	//place seeds
	for(map<string,BasicTerrain>::iterator it=mProbabilities.begin(); it!=mProbabilities.end(); ++it)
	{
		for(int i = 0; i < get<1>(*it).getSeeds(); i++)
		{
			try {
				int unseededIndex = rand() % unseeded.size();
				pair<int,int> coordinate = unseeded.at(unseededIndex);
				procMap->setTerrainWeight(get<0>(coordinate), get<1>(coordinate), get<1>(*it), 1);
				unseeded.erase(unseeded.begin()+unseededIndex);
			} catch (out_of_range& err) {
				break;
			}
		}
	}
	
	//go through the map until every tile is filled
	while(!done) {
		done = true;
		// we go through twice to make sure that the spreading doesn't go crazy
		for(int i = 0; i < procMap->getXSize(); i+=2)
		{
			for(int j = 0; j < procMap->getYSize(); j++)
			{
				done &= spread(i, j, procMap);
			}
		}
		for(int i = 1; i < procMap->getXSize(); i+=2)
		{
			for(int j = 0; j < procMap->getYSize(); j++)
			{
				done &= spread(i, j, procMap);
			}
		}
	}
}

/**
 * Add a new probability for a terrain
 * @param terrain The terrain to add a probability for. Only the name
 * of the terrain class is taken into account, so new calls to this function
 * with the same terrain class will overwrite the last one.
 */
void
BasicTerrainProbOption::setProbability(BasicTerrain terrain) {
	mProbabilities.insert(pair<string,BasicTerrain>(typeid(terrain).name(),terrain));
}

/**
 * Calculate the spreading of a tile at the given position
 * @param x The x coordinate of the tile
 * @param y The y coordinate of the tile
 * @return false if the tile is not set. True if it is.
 */
bool
BasicTerrainProbOption::spread(int x, int y, ProcMap* procMap)
{	
	bool ret = false;
	MapTile thisTile = procMap->getTile(x,y);
	map<string,int> thisWeightings = thisTile.getTerrainWeights();
	
	if( thisWeightings.size() == 0 )
		return false;
	
	// spread to immediately adjacent tiles
	// please, for the love of god, refactor
	//consume(&thisTile, &(map->getTile(x-1, y-1)));
	try{
		if( consume(thisTile, procMap->getTile(x, y-1)) ) {
			procMap->setTile(x, y-1, thisTile);
			ret = true;
		}
	} catch (exception& e) { }
	//consume(&thisTile, &(map->getTile(x+1, y-1)));
	try{
		if( consume(thisTile, procMap->getTile(x-1, y)) ) {
			procMap->setTile(x-1, y, thisTile);
			ret = true;
		}
	} catch (exception& e) { }
	try{
		if( consume(thisTile, procMap->getTile(x+1, y)) ) {
			procMap->setTile(x+1, y, thisTile);
			ret = true;
		}
	} catch (exception& e) { }
	//consume(&thisTile, &(map->getTile(x-1, y+1)));
	try{
		if( consume(thisTile, procMap->getTile(x, y+1)) ) {
			procMap->setTile(x, y+1, thisTile);
			ret = true;
		}
	} catch (exception& e) { }
	//consume(&thisTile, &(map->getTile(x+1, y+1)));
	return ret;
}

/**
 * overwrites spreadTo with spreadFrom if the randomness says so
 * @param spreadFrom the tile that is spreading
 * @param spreadTo the tile that is being spread to
 * @param map the map that this is occuring in
 * @return true if spreadTo was consumed by spreadFrom, false if either it was
 * not or the tile does not exist
 */
bool
BasicTerrainProbOption::consume(MapTile spreadFrom, MapTile spreadTo)
{
	
	// with basic terrains, we assume that there is only one weighting
	int fromWeight = get<1>(*(spreadFrom.getTerrainWeights().end()));
	int toWeight = get<1>(*(spreadTo.getTerrainWeights().end()));
	
	if( rand() % (fromWeight + toWeight) < fromWeight )
		return true;
	return false;
}
