// FILE:		Platform.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:

// COMMENTS:	This family of function is designed to act as abstraction 
//				layer, sperating the program from the device platform. The 
//				idea being that this should aid the task of porting the 
//				code to other platforms. (Known as forward planning :o)
//				Some prototype may have to change between platforms, however.

// INCLUDES:
#include	"Platform.h"
#include	"Agb.h"
#include	"BasicTypes.h"
#include	"BasicDefines.h"
#include	"Graphics.h"	// Circular include path?

// ----
// Initialise the platform so that it is ready to use.
// Returns true to indicate success, and FALSE to indicate failure
BOOL	Platform_Init()
{
	Platform_ClearAllMemory();
	return TRUE;
}

// ----
// This function will try and tell the user there is a 
// problem with the platform.
void	Platform_Error()
{
	COLOUR	Col;

	// The good old red screen of death.
	Graphics_Init(4);
	Graphics_SetPaletteColour(0, 255, 0, 0);
	Col.PaletteIndex = 0;
	Graphics_ClearScreen(Col);
	Graphics_SwapScreens();
	while(1);	// Stay here.
}

// ----
// Clear all RAM on the device.
void	Platform_ClearAllMemory()
{
	//Platform_ClearCPURAM();	// Stops program executing - probably over writing call stack.
	Platform_ClearWRAM();
	Platform_ClearVRAM();
	Platform_ClearOAM();
	Platform_ClearPalette();
}

// ----
// Clear CPU RAM.
void	Platform_ClearCPURAM()
{
	DmaClear(3, 0, CPU_WRAM, CPU_WRAM_SIZE - 0x200, 32);   // Internal CPU work RAM
}

// ----
// Clear Working RAM.
void	Platform_ClearWRAM()
{
	DmaClear(3, 0, EX_WRAM,  EX_WRAM_SIZE,          32);   // External CPU work RAM
}

// ----
// Clear Video RAM.
void	Platform_ClearVRAM()
{
	DmaClear(3, 0, VRAM,     VRAM_SIZE,             16);   // VRAM Clear
}

// ----
// Clear Object Attribute Memory. 
void	Platform_ClearOAM()
{
	DmaClear(3, 0, OAM,      OAM_SIZE,              16);   // OAM (sprite)
}

// ----
// Clear Palette memory.
void	Platform_ClearPalette()
{
	DmaClear(3, 0, PLTT,     PLTT_SIZE,             16);   // Palette
}
