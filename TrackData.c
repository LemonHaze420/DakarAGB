#include "TrackData.h"
#include <IsAgbPrint.h>
#include "malloc.h"
#include "Extern.h"
#include "Agb.h"

// are: I am going to (and have started to) replace this code by 
//		implementing it in the renderer -  keeps the code in one
//		place, and mine (that way I know what it is supposed to 
//		be doing, even if it isn't doing it correctly).


BOOL	InitTrackData(INTVECTOR Pos)
{
#if 0	// are: No

	char tile;
	int i, y;

	char* point;

	point = Viewport;

	LastIndex = (1) + (1 * 64);
	//LastIndex = 1 + 1 * 64; //temporary just want to get a track working first

	//ok so we have a hunk and where its pointing to, now I need to DMA
	//the data from the tile sets in ROM to RAM... this'll be fun, I can tell.

	track = malloc(sizeof(track));
	if(track == NULL)
	{
		//Can't link to debug libs but this should assert and crash here.
	}

	//now I want to load in the data for this section.
	//first find the track tile index for the top left tile
	tile = TestIndexArray[LastIndex - 65]; //-1 - 64

	for(i = 0; i < 64; i++)
	{
		DmaCopy(3, HeightTileArray[ (tile << 12) + (i << 6) ], track->HeightData[i][0], 64, 16);
	}

	//then 1 tile down and so on..
	
	tile = TestIndexArray[LastIndex - 1]; 

	for(i = 0; i < 64; i++)
	{
		DmaCopy(3, HeightTileArray[ (tile << 12) + (i << 6) ], track->HeightData[i + 64][0], 64, 16);
	}

	tile = TestIndexArray[LastIndex + 63]; 

	for(i = 0; i < 64; i++)
	{
		DmaCopy(3, HeightTileArray[ (tile << 12) + (i << 6) ], track->HeightData[i + 128][0], 64, 16);
	}

	tile = TestIndexArray[LastIndex - 64]; 

	for(i = 0; i < 64; i++)
	{
		DmaCopy(3, HeightTileArray[ (tile << 12) + (i << 6) ], track->HeightData[i][64], 64, 16);
	}

	tile = TestIndexArray[LastIndex]; 

	for(i = 0; i < 64; i++)
	{
		DmaCopy(3, HeightTileArray[ (tile << 12) + (i << 6) ], track->HeightData[i + 64][64], 64, 16);
	}

	tile = TestIndexArray[LastIndex + 64]; 

	for(i = 0; i < 64; i++)
	{
		DmaCopy(3, HeightTileArray[ (tile << 12) + (i << 6) ], track->HeightData[i + 128][64], 64, 16);
	}

	tile = TestIndexArray[LastIndex - 63]; 

	for(i = 0; i < 64; i++)
	{
		DmaCopy(3, HeightTileArray[ (tile << 12) + (i << 6) ], track->HeightData[i][128], 64, 16);
	}

	tile = TestIndexArray[LastIndex + 1]; 

	for(i = 0; i < 64; i++)
	{
		DmaCopy(3, HeightTileArray[ (tile << 12) + (i << 6) ], track->HeightData[i + 64][128], 64, 16);
	}

	tile = TestIndexArray[LastIndex + 65]; 

	for(i = 0; i < 64; i++)
	{
		DmaCopy(3, HeightTileArray[ (tile << 12) + (i << 6) ], track->HeightData[i + 128][128], 64, 16);
	}

	//ok cool, all my data for height SHOULD be in the array, I bloody well hope it is.

	//now I have to set up my view port, this shouldn't be too dificult... 
	//btw, I lied, it will be....

	for( i = 0; i < 32; i ++)
	{
		DmaCopy(3, track->HeightData[64 + i][64], point, 32, 16);
		point += 32;
	}
#endif
	
	return TRUE;
}

void	ProcessTrackViewer(INTVECTOR Pos)
{
#if 0	// are: No
	int	index;
	char tile;
	int i, y;
	char* point;


	index = (Pos.X) + (Pos.Y * 64);

	if(index == LastIndex)
		return;

	if( ((index%64) - (LastIndex%64)) > 16)
	{
		point = Viewport;

		LastIndex = (Pos.X) + (Pos.Y * 64);

		tile = TestIndexArray[LastIndex - 65]; //-1 - 64

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i][0], 64, 16);
		}

		//then 1 tile down and so on..
		
		tile = TestIndexArray[LastIndex - 1]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 64][0], 64, 16);
		}

		tile = TestIndexArray[LastIndex + 63]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 128][0], 64, 16);
		}

		tile = TestIndexArray[LastIndex - 64]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i][64], 64, 16);
		}

		tile = TestIndexArray[LastIndex]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 64][64], 64, 16);
		}

		tile = TestIndexArray[LastIndex + 64]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 128][64], 64, 16);
		}

		tile = TestIndexArray[LastIndex - 63]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i][128], 64, 16);
		}

		tile = TestIndexArray[LastIndex + 1]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 64][128], 64, 16);
		}

		tile = TestIndexArray[LastIndex + 65]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 128][128], 64, 16);
		}

		//ok cool, all my data for height SHOULD be in the array, I bloody well hope it is.

		//now I have to set up my view port, this shouldn't be too dificult... 
		//btw, I lied, it will be....

		for( i = 0; i < 32; i ++)
		{
			DmaCopy(3, &track->HeightData[64 + i][64], point, 32, 16);
			point += 32;
		}
	}
	else if( ((index>>6) - (LastIndex>>6)) > 16)
	{
		
		point = Viewport;

		LastIndex = (Pos.X) + (Pos.Y * 64);

				for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i][0], 64, 16);
		}

		//then 1 tile down and so on..
		
		tile = TestIndexArray[LastIndex - 1]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 64][0], 64, 16);
		}

		tile = TestIndexArray[LastIndex + 63]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 128][0], 64, 16);
		}

		tile = TestIndexArray[LastIndex - 64]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i][64], 64, 16);
		}

		tile = TestIndexArray[LastIndex]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 64][64], 64, 16);
		}

		tile = TestIndexArray[LastIndex + 64]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 128][64], 64, 16);
		}

		tile = TestIndexArray[LastIndex - 63]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i][128], 64, 16);
		}

		tile = TestIndexArray[LastIndex + 1]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 64][128], 64, 16);
		}

		tile = TestIndexArray[LastIndex + 65]; 

		for(i = 0; i < 64; i++)
		{
			DmaCopy(3, &HeightTileArray[ (tile << 12) + (i << 6) ], &track->HeightData[i + 128][128], 64, 16);
		}

		//ok cool, all my data for height SHOULD be in the array, I bloody well hope it is.

		//now I have to set up my view port, this shouldn't be too dificult... 
		//btw, I lied, it will be....

		for( i = 0; i < 32; i ++)
		{
			DmaCopy(3, &track->HeightData[64 + i][64], point, 32, 16);
			point += 32;
		}
	}
#endif
}

