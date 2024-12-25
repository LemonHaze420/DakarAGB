
#include	"BasicTypes.h"	// Types

#define	DAKAR_TILE_COUNT		128
#define	DAKAR_NUMBER_OF_TRACKS	12

// // Define each of the track splines here.
const	UBYTE	Dakar_TrackOne		[256];
const	UBYTE	Dakar_TrackTwo		[256];
const	UBYTE	Dakar_TrackThree	[256];
const	UBYTE	Dakar_TrackFour		[256];
const	UBYTE	Dakar_TrackFive		[256];
const	UBYTE	Dakar_TrackSix		[256];
const	UBYTE	Dakar_TrackSeven	[256];
const	UBYTE	Dakar_TrackEight	[256];
const	UBYTE	Dakar_TrackNine		[256];
const	UBYTE	Dakar_TrackTen		[256];
const	UBYTE	Dakar_TrackEleven	[256];
const	UBYTE	Dakar_TrackTwelve	[256];

// Maintain an array of the spline array addresses.
const	UBYTE*	Dakar_TrackArrayList[DAKAR_NUMBER_OF_TRACKS] = {
																	Dakar_TrackOne,
																	Dakar_TrackTwo,	
																	Dakar_TrackThree,
																	Dakar_TrackFour,
																	Dakar_TrackFive,
																	Dakar_TrackSix,
																	Dakar_TrackSeven,
																	Dakar_TrackEight,
																	Dakar_TrackNine,
																	Dakar_TrackTen,
																	Dakar_TrackEleven,
																	Dakar_TrackTwelve
																};

// Define all the tile heights here.
const	UBYTE	Dakar_TileHeightArray[1024	* DAKAR_TILE_COUNT];	// 32 * 32 * ...
const	UBYTE	Dakar_TileColourArray[256	* DAKAR_TILE_COUNT];	// 16 * 16 * ...

