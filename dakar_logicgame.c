// FILE:		Dakar_LogicGame.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// COMMENTS:	This file contains the Dakar in-game code.

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

extern INT	gg;
INT jj; //was in the extern above
VPOINT viewableTrack[30];
BOOL	method;

extern void	Dakar_Render(void);
extern void	Dakar_RefreshMap(void);

// ----
// Start a new game from scratch.
void	Dakar_InitGameData()
{
	// This function was intended for use in setting 
	// players name, clearing score / counters

	// data for actual race should, however, be assigned in Dakar_GameInit.
}

// ----
// Load in-game data / prepare for race.
BOOL	Dakar_GameInit()
{
	INT tt;
	SHWORD	bg_pa, bg_pb, bg_pc, bg_pd;
	SWORD	bg_start_x, bg_start_y;
	SHWORD	bg_pos_x, bg_pos_y;


	// Re-initialise all interrupts.
	Interrupts_Init();

	// Assign in-game callbacks.
	Interrupts_SetCallback(EInterrupt_VerticalBlank, Dakar_GameVerticalBlank);
//	Interrupts_SetCallback(EInterrupt_HorizontalBlank, Dakar_GameHorizontalBlank);

	// Change video modes.
	Platform_ClearVRAM();
	Graphics_SetGraphicsMode(4);	// Bitmpa modes the way to go.

	// Turn on and off particular BGs.
	Graphics_SetBackground(0, 0);	// BG0 on
	Graphics_SetBackground(1, 0);	// BG1 on
	Graphics_SetBackground(2, 1);	// On
	Graphics_SetBackground(3, 0);	// Off - for now.
	
	// Mosaic
	Graphics_SetBackgroundMosiac(2, FALSE);		// Turn off mosaic.

	// Repeat mode
	Graphics_SetBackgroundTransparency(2, 0);	// No repeat

	// Set screen orientation.
	// Scale by 1.5 times in both axis, and rotate through 270 degrees - to bring it back on
	bg_pos_x = 67;
	bg_pos_y = 40;

	//  pa = cos(bg_rotate)*(1/bg_scale_x)
    bg_pa = fix_mul(_Cos(192), fix_inverse(0x182));

	//  pb = sin(bg_rotate)*(1/bg_scale_x)
    bg_pb = fix_mul(_Sin(192), fix_inverse(0x182));

	//  pc =-sin(bg_rotate)*(1/bg_scale_y)
    bg_pc = fix_mul(-_Sin(192), fix_inverse(0x300/*180*/));

	//  pd = cos(bg_rotate)*(1/bg_scale_y)
    bg_pd = fix_mul(_Cos(192), fix_inverse(0x300/*180*/));

	//  Set starting point for reference

	//  120-bg_pos_x in the first line is for 
	// adjustment because bg_pos_x = 0 is center of screen. 
	//  Lower 2 lines are for matrix calculation.
	//  Assume center of rotation/scaling as center of screen 

    bg_start_x = ((120-bg_pos_x)<<8)
	- ( bg_pa * 120 )
	- ( bg_pb * 80 );
    bg_start_y = ((80-bg_pos_y)<<8)
	- ( bg_pc * 120 )
	- ( bg_pd * 80 );

	// X - High and Low.
	*(UHWORD*)BGXHRegs[2]	= (u16)(u32)((bg_start_x & 0x0fff0000)>>16);
	*(UHWORD*)BGXLRegs[2]	= (bg_start_x & 0xffff);

	// Y - High and Low.
	*(UHWORD*)BGYHRegs[2]	= (u16)(u32)((bg_start_y & 0x0fff0000)>>16);
	*(UHWORD*)BGYLRegs[2]	= (bg_start_y & 0xffff);
	
	*(UHWORD*)BGPARegs[2]	= (SHWORD)bg_pa;
	*(UHWORD*)BGPBRegs[2]	= (SHWORD)bg_pb;
	*(UHWORD*)BGPCRegs[2]	= (SHWORD)bg_pc;
	*(UHWORD*)BGPDRegs[2]	= (SHWORD)bg_pd;

	// The display will effectively be 160x106. 
	// Addressing from the bottom left hand corner, with 
	// x-axis up the display, and y-axis across display. 
	// This reduces screen resolution, and means I can use 
	// the DMA to help with the drawing of my bars.

	Col.PaletteIndex = 0;
	Graphics_ClearScreen(Col);

	Col.PaletteIndex = 1;
	for (tt = 1; tt < 160; tt++)
	{
		Col.PaletteIndex = tt % 2;
		Graphics_DrawLineXYXY(0,tt, 106,tt, Col);
	}
	Graphics_SwapScreens();

	// Sound, etc

	// Load data.
	Dakar_LoadGame();

	InitTrackData(Dakar_ViewPosition);

	// Set up vehicle data.
	Car_CarInit(playersCar);

	// Clear states and enable interupts.
	Interrupts_ClearAllInterruptStates();
	Interrupts_SetState(TRUE);

	// ----
	// Init the track / renderer stuff.

	// Initialise the track data, etc, so we start on the 
	// first track - if we want to allow game continuation
	// later then we can do that elsewhere.
	Dakar_TrackNumber		= 0;	// First track.
	Dakar_TrackPosition		= 0;	// Start of the track.

	Dakar_TrackArrayPointer	= Dakar_TrackArrayList[Dakar_TrackNumber];

	// Read to go into game
	Dakar_State	= EDakarState_Game;
	return TRUE;
}

// ----
// Play the bloody game.
// This may require stubs. i.e Dakar_GameProcessAI(), etc.
BOOL	Dakar_Game()
{
	INT	a, i;

	// Right, so how is the game going to work.
	// Basically, the system is going to be interrupt driven - consequently 
	// this code is going to look a little 'odd'.

	// When the vertical blank is triggered we will have time to process the game code, etc. 
	// Outside the vertical blank time we shalln't (initially) process anything. This code is

	Dakar_SetCamera();

	gg = 0;
	jj = 0;
	//InitTrackData(track, 0);
	//Car_CarInit(playersCar);
	Interrupts_ClearAllInterruptStates();
	Dakar_ContinueRace	= TRUE;

	Dakar_SetUpRender();

	for(i = 0; i < 256; i++)
	{
		TrackPalette[i] = i << PLTT_RED_SHIFT;
	}
	DmaArrayCopy(1, TrackPalette,	OBJ_PLTT,	16);

	while (Dakar_ContinueRace)
	{
#if 1
		if (Interrupts_Check & V_BLANK_INTR_FLAG)
#endif
		{
//			Graphics_RotateScaleBackground(2, 0x140, 0x140, jj);

			// Do our processing here.
			//Car_MoveCar(playersCar,TargetConfigIndex,SourceConfigIndex);

			Dakar_RefreshMap();	// This function needs to be completed - waiting on track data format.
			Dakar_Render();
			Graphics_SwapScreens();

			Controls_Process();

			// Rotation
			if (Controls_IsButtonPressed(FireB))
			{
				Dakar_ViewDirection.Y -= 3;
			}
			if (Controls_IsButtonPressed(FireA))
			{
				Dakar_ViewDirection.Y += 3;
			}

			// Translation
			if (Controls_IsButtonPressed(Up))
			{
				Dakar_ViewPosition.X += _Sin(Dakar_ViewDirection.Y & 0xFF) >> 3;
				Dakar_ViewPosition.Y += _Cos(Dakar_ViewDirection.Y & 0xFF) >> 3;
			}
			if (Controls_IsButtonPressed(Down))
			{
				Dakar_ViewPosition.X -= _Sin(Dakar_ViewDirection.Y & 0xFF) >> 3;
				Dakar_ViewPosition.Y -= _Cos(Dakar_ViewDirection.Y & 0xFF) >> 3;
			}
			
			if (Controls_IsButtonPressed(Start))
			{
				Dakar_ViewPosition.X	= IntToFP16(50);
				Dakar_ViewPosition.Y	= IntToFP16(50);
				Dakar_ViewDirection.Y	= 0;
			}

			if (Controls_IsButtonPressedDB(Select))
			{
				method ^= 1;
			}
		}

		Halt();	// Send process to sleep until an interrupt occurs.
	}

	// Nothing happen here yet.
	Dakar_State	= EDakarState_MenuInit;

	return TRUE;
}