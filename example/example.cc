#include "example.hh"

void
drawMap(ProcMap pMap)
{
	printf("yeah!\n");
	
	for( int i = 0; i < pMap.getYSize(); i++ )
	{
		for( int j = 0; j < pMap.getXSize(); j++ )  
		{
			MapTile tile = pMap.getTile(j, i);
			set<int>::iterator it = tile.getTerrains().begin();
			int terrain = *it;
			if( terrain == 1 )
				printf("|");
			else if( terrain == 2 )
				printf("~");
			else if( terrain == 3 )
				printf("_");
			else
				printf("\\");
		}
		printf("\n");
	}
			
}

int
main()
{
	srand(time(NULL));
	
	BasicTerrain grass = BasicTerrain( 5, 100 );
	BasicTerrain water = BasicTerrain( 9, 100 );
	BasicTerrain ground = BasicTerrain( 2, 300 );
	
	grass.setId(1);
	water.setId(2);
	ground.setId(3);
	
	BasicTerrainProbOption terrainOption = BasicTerrainProbOption();
	terrainOption.setProbability(grass);
	terrainOption.setProbability(water);
	terrainOption.setProbability(ground);
	
	ProcMapOptions options = ProcMapOptions();
	options.setSize( 50, 40 );
	options.addTerrainOption(&terrainOption);
	
	ProcMap pMap = options.runOptions();
	
	drawMap(pMap);
	
}
