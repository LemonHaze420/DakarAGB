// FILE:		Dakar_Logic.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// COMMENTS:	This file contains the Dakar code that has no-where better to live.

// INCLUDES:
#include	"Dakar.h"

#include	"Agb.h"	
#include	"BasicTypes.h"	// Types
#include	"BasicDefines.h"// Defines
#include	"Debug.h"		// Debugging tools
#include	"Macros.h"		// Useful macros.

#include	"Platform.h"	// Platform abstraction layer.
#include	"Interrupts.h"	// Interrupt handling
#include	"Graphics.h"	// Graphics functions.
#include	"Controls.h"	// Control functions.
#include	"Sound.h"		// Sound functions.

#include	"Extern.h"		// Access to data.
#include	"share.h"		// Temp  code - this shall be replaced / moved.	(Nothing to do with shared data!!!)

// ----
// Initialise the function 'jump' arrays.
void	Dakar_InitStateTables()
{
	INT	i;

	// Set all values in jump table to NULL.
	for (i = NUMBER_OF_GAME_STATES; i--;)
	{
		Dakar_StateTable[i]	= NULL;
	}

	// Assign the values we do have.
	Dakar_StateTable[(INT)EDakarState_Start]		= Dakar_Start;
	Dakar_StateTable[(INT)EDakarState_Splash]		= Dakar_Splash;
	Dakar_StateTable[(INT)EDakarState_MenuInit]		= Dakar_MenuInit;
	Dakar_StateTable[(INT)EDakarState_Menu]			= Dakar_Menu;
	Dakar_StateTable[(INT)EDakarState_GameInit]		= Dakar_GameInit;
	Dakar_StateTable[(INT)EDakarState_Game]			= Dakar_Game;

	// Future use.
	/*
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	Dakar_StateTable[(INT)]		= Dakar_;
	*/

	// Set start point.
	Dakar_State	= EDakarState_Start;
}