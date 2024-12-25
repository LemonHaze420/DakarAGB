// FILE:		Dakar_DataEvents.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// COMMENTS:	Function in this file should load data for a set event.
//				That is to say I want to see function such as 
//				Dakar_LoadMenu(), which loads all the data for the menu
//				and not loads of functions such as Dakar_LoadCar(). 
//				Those kind of functions can be hidden in Dakar_DataItems.c
//				- and they will require some thought, 'cos we don't know 
//				what data we are going to have yet and where to store it.

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

#include	"MainbackGround.c"

// ----
// Load data for splash screen.
void	Dakar_LoadSplash()
{
	UBYTE i, j;

	Platform_ClearVRAM();
	DmaArrayCopy(3, Alphaset1_Char,		BG_VRAM+0x4000, 16);
	DmaArrayCopy(3, Alphaset1_Palette,	BG_PLTT,        16);

	*(UHWORD*)(BG_VRAM + 24)		= 'D' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 26)		= 'A' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 28)		= 'K' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 30)		= 'A' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 32)		= 'R' - 'A' + 1;

	*(UHWORD*)(BG_VRAM + 60 + 18)	= 'G' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 20)	= 'A' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 22)	= 'M' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 24)	= 'E' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 26)	= 'B' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 28)	= 'O' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 30)	= 'Y' - 'A' + 1;
	// Skip					  32
	*(UHWORD*)(BG_VRAM + 60 + 34)	= 'A' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 36)	= 'D' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 38)	= 'V' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 40)	= 'A' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 42)	= 'N' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 44)	= 'C' - 'A' + 1;
	*(UHWORD*)(BG_VRAM + 60 + 46)	= 'E' - 'A' + 1;
}

// ----
// Load all the data for the game menu system.
void	Dakar_LoadMenu()
{
	INT i,j;

	Platform_ClearVRAM();
	DmaArrayCopy(3, Alphaset1_Char,		BG_VRAM+0x4000,	32);	// Block 1.
//	DmaArrayCopy(3, Alphaset1_Palette,	BG_PLTT,		32);

	DmaArrayCopy(3, MainMenu_Character,	BG_VRAM+0x8000,	32);	// Block 2.		
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 30; j++)
		{
			*(UHWORD*)(BG_VRAM+0x0800 + 2 *(i * 32 + j))	= *(UBYTE*)(MainMenu_Map + i * 30 + j);
		}
	}
	DmaArrayCopy(3, MainMenu_Palette,	BG_PLTT,		32);

/*
	// Standard PS2 background.
	DmaArrayCopy(3, MainBackground_Char,	BG_VRAM+0x8000, 32);
	DmaArrayCopy(3, MainBackground_Palette,	BG_PLTT,        32);
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 30; j++)
		{
			*(UHWORD*)(BG_VRAM+0x0800 + 2 *(i * 32 + j))	= (i * 30 + j);
		}
	}
*/
}

// ----
// Load in game data.
void	Dakar_LoadGame()
{
	INT	i, j;

#if 0
	Platform_ClearVRAM();

	// Load in bog standard text characters for now.
	DmaArrayCopy(3, Alphaset1_Char,		BG_VRAM+0x4000,	32);	// Block 1.

	// Load in tile map and associated character set.
	DmaArrayCopy(3, Track_Character,	BG_VRAM+0x4000,				32);	// Block 2
//	DmaArrayCopy(3, Track_Map,			Graphics_Buffer[2].Address,	32);	// DMA map to screen address
#endif

	/*
	// Process map into Map.
	for (i = 256; i--;)
	{
		for (j = 256; j--;)
		{
			Map[i][j].Alt = Map_IndexBitmap[i * 256 + j];
			Map[i][j].Col = Map_IndexBitmap[i * 256 + j];
		}
	}
  */


	// Set all in-game position / orientation data to zero for the time being.
	Dakar_ViewPosition.X	= 0;
	Dakar_ViewPosition.Y	= 0;
	Dakar_ViewPosition.Z	= 0;

	Dakar_ViewDirection.X	= 0;
	Dakar_ViewDirection.Y	= 0;
	Dakar_ViewDirection.Z	= 0;
}
