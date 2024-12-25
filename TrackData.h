#ifndef	_TRACKDATA_H_
#define	_TRACKDATA_H_

#include	"BasicTypes.h"
#include	"Matrix.h"
#include	"BasicDefines.h"
#include	"Extern.h"
#include	"AgbMacro.h"

//this will load up all the data needed at the start into track and set up the initial 
//view.
BOOL	InitTrackData(INTVECTOR Pos);

//This will move the VIEWABLE_TRACK matrix to show where the car is
void	ProcessTrackViewer( INTVECTOR Pos);

//this will load up new data into track.
void	MoveTrackHunk(HUNK track, CHAR moveX, CHAR moveY);

//Variables and stuff
int LastIndex; //has both x and y position inside it.

HUNK *track;


#endif