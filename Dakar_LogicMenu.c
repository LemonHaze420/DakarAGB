// FILE:		Dakar_LogicMenu.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// COMMENTS:	This file contains Dakar menu code.

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

#include	"sdtio.h"		// A selective implementation of stdio routines.


// ----
// Start things off - init display resolution, etc.
BOOL	Dakar_Start()
{
	// Assign menu v-blank handler.
	Interrupts_SetState(FALSE);
	Interrupts_ClearAllInterruptStates();
	Interrupts_SetCallback(EInterrupt_VerticalBlank, Dakar_MenuVBlankHandler);
	Interrupts_SetState(TRUE);

	// Nothing here yet, so simply move on to next mode..
	Dakar_State = EDakarState_Splash;

	return TRUE;
}

// ----
// Show splash screens / animations.
BOOL	Dakar_Splash()
{
	// Turn off interrupts
	Interrupts_SetState(FALSE);

	// Load in splash artwork.
	Dakar_LoadSplash();
	
	// Change video modes.
	Graphics_SetGraphicsMode(0);

	// Turn on and off particular BGs.
	Graphics_SetBackground(0, 1);	// BG0 on
	Graphics_SetBackground(1, 0);	// BG1 off
	Graphics_SetBackground(2, 0);	// Off
	Graphics_SetBackground(3, 0);	// Off

	// Set particular BG attributes
	Graphics_SetBackgroundColourMode(0, 1);		// 256 colour.
	Graphics_SetBackgroundCharBaseBlock(0, 1);	// Reference char block 1. (See P38 of AGB Programming Manual).
	Graphics_SetBackgroundMosiac(0, FALSE);		// Turn off mosaic.
	Graphics_SetBackgroundPriority(0, 0);		// Set highest priority.
	
	// Enable interupts and clear states.
	Interrupts_SetState(TRUE);
	Interrupts_ClearAllInterruptStates();

	// Sit in loop waiting for 'start' key to be press
	// (for now, until I get timers implemented).
	while (TRUE)
	{
		Controls_Process();
		if (Controls_IsButtonPressedDB(Start))
			break;

		Interrupts_WaitVerticalBlank();
	}

	// Move to menu load state.
	Dakar_State	= EDakarState_MenuInit;

	return TRUE;
}

// ----
// Initialise the function 'jump' arrays.
BOOL	Dakar_MenuInit()
{
	// Turn off all interrupts and setup menu interrupt routines
	Interrupts_Init();
	Interrupts_SetCallback(EInterrupt_VerticalBlank, Dakar_MenuVBlankHandler);

	// Load in splash artwork.
	Dakar_LoadMenu();
	
	// Change video modes.
	Graphics_SetGraphicsMode(0);

	// Turn on and off particular BGs.
	Graphics_SetBackground(0, 1);	// BG0 on
	Graphics_SetBackground(1, 1);	// BG1 on
	Graphics_SetBackground(2, 1);	// On
	Graphics_SetBackground(3, 1);	// On

	// Set where tile maps are stored.
	Graphics_SetBackgroundScreenBaseBlock(0, 0);// Base block 0.	(VRAM + 0 * 2048).
	Graphics_SetBackgroundScreenBaseBlock(1, 1);// Base block 1.	(VRAM + 1 * 2048).
	Graphics_SetBackgroundScreenBaseBlock(2, 2);// Base block 2.	(VRAM + 2 * 2048).
	Graphics_SetBackgroundScreenBaseBlock(3, 3);// Base block 3.	(VRAM + 3 * 2048).

	// Set where tiles are stored
	Graphics_SetBackgroundCharBaseBlock(0, 1);	// Reference char block 1. (See P38 of AGB Programming Manual).
	Graphics_SetBackgroundCharBaseBlock(1, 2);	// Reference char block 1. (See P38 of AGB Programming Manual).
	Graphics_SetBackgroundCharBaseBlock(2, 1);	// Reference char block 1. (See P38 of AGB Programming Manual).
	Graphics_SetBackgroundCharBaseBlock(3, 1);	// Reference char block 1. (See P38 of AGB Programming Manual).

	// All colour modes.
	Graphics_SetBackgroundColourMode(0, 1);		// 16 colour.
	Graphics_SetBackgroundColourMode(1, 1);		// 16 colour.
	Graphics_SetBackgroundColourMode(2, 1);		// 16 colour.
	Graphics_SetBackgroundColourMode(3, 1);		// 16 colour.

	// Mosaic
	Graphics_SetBackgroundMosiac(0, FALSE);		// Turn off mosaic.
	Graphics_SetBackgroundMosiac(1, FALSE);		// Turn off mosaic.
	Graphics_SetBackgroundMosiac(2, FALSE);		// Turn off mosaic.
	Graphics_SetBackgroundMosiac(3, FALSE);		// Turn off mosaic.

	// Set BG order priority.
	Graphics_SetBackgroundPriority(0, 0);		
	Graphics_SetBackgroundPriority(1, 1);		
	Graphics_SetBackgroundPriority(2, 2);		
	Graphics_SetBackgroundPriority(3, 3);		
	

	// Lowest
	// Middle-low
	// Middle-high
	// Highest


	// Enable interupts and clear states.
	Interrupts_SetState(TRUE);
	Interrupts_ClearAllInterruptStates();

	// Move to menu state.
	Dakar_State			= EDakarState_Menu;
	Dakar_MenuCurrPos	= 0;
	Dakar_MenuPrevPos	= 0;

	return TRUE;
}

// ----
BOOL	Dakar_Menu()
{
	INT	i;
	
	// Draw menu title
	Dakar_MenuDrawString(	0, 
							15, 
							8, 
							"MAIN MENU",
							TEXT_CENTRED);

	// Draw options.
	Dakar_MenuDrawString(	0, 
							15,
							11, 
							"CHAMPIONSHIP",
							TEXT_CENTRED);

	Dakar_MenuDrawString(	0, 
							15,
							12, 
							"SINGLE RACE",
							TEXT_CENTRED);

	Dakar_MenuDrawString(	0, 
							15, 
							13, 
							"ARCADE",
							TEXT_CENTRED);

	Dakar_MenuDrawString(	0, 
							15, 
							14, 
							"HALL OF FAME",
							TEXT_CENTRED);

	Dakar_MenuDrawString(	0, 
							15, 
							15, 
							"CREDITS",
							TEXT_CENTRED);

	// Update menu pos.
	Controls_Process();
	if (Controls_IsButtonPressedDB(Down))
	{
		Dakar_MenuCurrPos++;
	}
	if (Controls_IsButtonPressedDB(Up))
	{
		Dakar_MenuCurrPos--;
	}
	if (Dakar_MenuCurrPos > 4)
		Dakar_MenuCurrPos = 0;
	if (Dakar_MenuCurrPos < 0)
		Dakar_MenuCurrPos = 4;

	if (Controls_IsButtonPressedDB(FireA))
	{
		switch (Dakar_MenuCurrPos)
		{
		case 0:
			Dakar_State = EDakarState_GameInit;
			break;

		default:
			Dakar_MenuNotPossible(1);
			break;
		}
	}

	// Draw option highlighter
	for (i = 0; i < 5; i++)
	{
		if (i == Dakar_MenuCurrPos)
			*Buffer = 'A';
		else
			*Buffer = ' ';
		*(Buffer + 1) = 0;
		Dakar_MenuDrawString(	0, 
								6, 
								11 + i, 
								Buffer,
								TEXT_NORMAL);
	}

	// Finally process any effects on this screen and then wait for Vblank.
	Dakar_MenuProcessEffects();
	Interrupts_WaitVerticalBlank();

	return TRUE;
}

// ----
// Vertical blank interrupt handler for the menu system
static void Dakar_MenuVBlankHandler()
{
	Interrupts_Check |= V_BLANK_INTR_FLAG;
	*(UHWORD*)REG_IF |= V_BLANK_INTR_FLAG;

//	Graphics_RotateScaleBackground(2, 0x100 + gj, 0x100 + gj, gk);
}

// ----
// A string drawing routing specific to the menus. 
// This is only temporary as I have no idea where artwork will end up.
void	Dakar_MenuDrawString(INT	_BG,
							 INT	_X,
							 INT	_Y, 
							 CHAR*	_String,
							 UBYTE	_Style)
{
	CHAR*	Index;
	CHAR	Char;
	SBYTE	Offset;
	Index = _String;


	Offset = 0;
	if (_Style & TEXT_CENTRED)
		Offset = -(strlen(_String) >> 1);

	while (*Index)
	{
		Char = *Index;
		if ((Char < 65) && (Char >= (65 + 26)))
		{
			Char = 0;	// Clear unknown chars
		}
		*(UHWORD*)(Graphics_Buffer[_BG].Address + 2 * (32 * _Y + _X + Offset)) = Char - 'A' + 1;
		
		Index++;
		_X++;
	}
}

// ----
// Shake the specified screen.
void	Dakar_MenuNotPossible(INT	_BG)
{
	INT	i;

	for (i = NUMBER_OF_MENU_EFFECTS; i--;)
	{
		if (!Dakar_MenuEffect[i].Effect)
		{
			Dakar_MenuEffect[i].Effect	= 1;
			Dakar_MenuEffect[i].X		= 8;
			break;
		}
	}
}

// ----
// Process effects
void	Dakar_MenuProcessEffects()
{
	INT i;

	for (i = NUMBER_OF_MENU_EFFECTS; i--;)
	{
		if (Dakar_MenuEffect[i].Effect)
		{
			switch (Dakar_MenuEffect[i].Effect)
			{
			case 1:	// Shake screen
				Graphics_OffsetBackground(1, Dakar_MenuEffect[i].X, 0);
				Dakar_MenuEffect[i].X = -(Dakar_MenuEffect[i].X >> 1);

				if (!Dakar_MenuEffect[i].X)
				{
					Dakar_MenuEffect[i].Effect = 0;
				}
				break;

			default:
				// Don't care.
				break;
			}
		}
	}
}