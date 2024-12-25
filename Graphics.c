// FILE:		Graphics.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:

// INCLUDES:
#include	<agb.h>
#include	"share.h"

#include	"Graphics.h"
#include	"AgbDefine.h"
#include	"BasicDefines.h"
#include	"AdditionalAGBDefines.h"
#include	"Macros.h"
#include	"Extern.h"
#include	"Debug.h"

// What should be "protected" variables.
//extern BYTE*	Graphics_WorkingBuffer;
//extern BYTE*	Graphics_Buffer[GRAPHICS_MAX_BUFFERS];

#define		PUT_PIXEL_CORE_PAL8(x, y, col)	*(UBYTE*)(Graphics_Buffer[Graphics_ActiveScreen].Address + (Graphics_Buffer[Graphics_ActiveScreen].Width * y) + x) = col;
#define		PUT_PIXEL_CORE_PAL16(x, y, col)	*(UHWORD*)(Graphics_Buffer[Graphics_ActiveScreen].Address + (Graphics_Buffer[Graphics_ActiveScreen].Width * y) + x) = col;
// ----
// Initialise the graphics system.

void	Graphics_Init(UBYTE _Mode)
{
	INT	i;

	*(UHWORD*)REG_DISPCNT	= 1;
	*(UHWORD*)REG_BG0CNT	= 0;
	*(UHWORD*)REG_BG1CNT	= 0;
	*(UHWORD*)REG_BG2CNT	= 0;
	*(UHWORD*)REG_BG3CNT	= 0;

	Graphics_DisplayMode = _Mode;

	switch (_Mode)
	{
	case 0:
		Graphics_SetGraphicsMode(_Mode);
		
		// Loop through all the BGs set the properties accordingly.
		for (i = 4; i--;)
		{
			Graphics_SetBackgroundMosiac(i, 0);			// No mosaic.
			Graphics_SetBackgroundPriority(i, 2);		// Default to middle priority for all BGs. 
			Graphics_SetBackgroundScreenSize(i, 0);		// Set all screens to smallest sizes.
			Graphics_SetBackgroundScreenBaseBlock(i, i);// Set memory vectors accordingly.
		}
		break;

	case 1:
		Graphics_SetGraphicsMode(_Mode);
		
		// Loop through all the BGs set the properties accordingly.
		for (i = 3; i--;)
		{
			Graphics_SetBackgroundMosiac(i, 0);			// No mosaic.
			Graphics_SetBackgroundPriority(i, 2);		// Default to middle priority for all BGs. 
			Graphics_SetBackgroundScreenSize(i, 0);		// Set all screens to smallest sizes.
			Graphics_SetBackgroundScreenBaseBlock(i, i);// Set memory vectors accordingly.
		}

		break;


	case 2:
		Graphics_SetGraphicsMode(_Mode);
		
		// Loop through all the BGs set the properties accordingly.
		for (i = 4; i--;)
		{
			Graphics_SetBackgroundMosiac(i, 0);			// No mosaic.
			Graphics_SetBackgroundPriority(i, 2);		// Default to middle priority for all BGs. 
			Graphics_SetBackgroundScreenSize(i, 0);		// Set all screens to smallest sizes.
			Graphics_SetBackgroundScreenBaseBlock(i, i);// Set memory vectors accordingly.
		}
		break;

	case 3:
	case 4:
	case 5:
		Graphics_SetGraphicsMode(_Mode);
		Graphics_SetBackgroundMosiac(2, 0);			// No mosaic (bitmap is considered BG2)
		Col.PaletteIndex	= 0;					// Clear to colour 0.
		Graphics_ClearScreen(Col);
		break;

	default:
		ERROR_PATH_TRAP("Attempt to set an unsupported graphics mode.")
		break;
	}

	// Copy triangle rendering code into RAM.
	DmaCopy(3, Graphics_DrawFilledTriangle, Graphics_DrawTriBuffer, sizeof(Graphics_DrawTriBuffer), 32);
	Graphics_DrawTriCode = Graphics_DrawTriBuffer;

	//set up a palette for my use dammit
	for(i = 0; i < 255; i++)
	{
		TrackPalette[i] = i << PLTT_GREEN_SHIFT;
	}

	TrackPalette[255] = 125 << PLTT_BLUE_SHIFT; //i.e blue sky.. I hope


}

// ----
// Change to using a specific graphics mode.
void	Graphics_SetGraphicsMode(UBYTE	_Mode)
{
	switch (_Mode)
	{
//#ifdef GRAPHICS_SUPPORT_MODE_0
	case 0:
		// All BGs abailable. 
		// All in plain text mode. (i.e. no scaling or rotation).

		// Hardware modifying code.
		*(UHWORD*)REG_DISPCNT	= ((*(UHWORD*)REG_DISPCNT) & 0xFFF8) | 0;				// Mode 0.
		CLEAR_BIT_AT_ADDRESS(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_FRAME_BUFFER_BIT);	// Select first frame buffer.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG0_BIT);			// Turn on BG0.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG1_BIT);			// Turn on BG1.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG2_BIT);			// Turn on BG2.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG3_BIT);			// Turn on BG3.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_OAM_BIT);			// Turn on sprites.
		break;
//#endif	// End '#ifdef GRAPHICS_SUPPORT_MODE_0'

//#ifdef GRAPHICS_SUPPORT_MODE_1
	case 1:	
		// BG0, 1, 2 available. 
		// BG3 is disabled. 
		// BG0, 1 are plain text modes.
		// BG2 can be used for scaling and rotation.
		
		// Hardware modifying code.
		*(UHWORD*)REG_DISPCNT	= ((*(UHWORD*)REG_DISPCNT) & 0xFFF8) | 1;				// Mode 1.
		CLEAR_BIT_AT_ADDRESS(	REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_FRAME_BUFFER_BIT);// Select first frame buffer.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG0_BIT);			// Turn on BG0.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG1_BIT);			// Turn on BG1.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG2_BIT);			// Turn on BG2.
		CLEAR_BIT_AT_ADDRESS(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG3_BIT);			// Turn off BG3.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_OAM_BIT);			// Turn on sprites.
		break;
//#endif	// End '#ifdef GRAPHICS_SUPPORT_MODE_1'

//#ifdef GRAPHICS_SUPPORT_MODE_2
	case 2:	
		// Hardware modifying code.
		*(UHWORD*)REG_DISPCNT	= ((*(UHWORD*)REG_DISPCNT) & 0xFFF8) | 2;				// Mode 2.
		CLEAR_BIT_AT_ADDRESS(	REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_FRAME_BUFFER_BIT);// Select first frame buffer.
		CLEAR_BIT_AT_ADDRESS(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG0_BIT);			// Turn off BG0.
		CLEAR_BIT_AT_ADDRESS(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG1_BIT);			// Turn off BG1.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG2_BIT);			// Turn on BG2.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG3_BIT);			// Turn on BG3.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_OAM_BIT);			// Turn on sprites.
		break;
//#endif	// End '#ifdef GRAPHICS_SUPPORT_MODE_2'

//#ifdef GRAPHICS_SUPPORT_MODE_3
	case 3:	
		// Not implemented
		break;
//#endif	// End '#ifdef GRAPHICS_SUPPORT_MODE_3'

//#ifdef GRAPHICS_SUPPORT_MODE_4
	case 4:
		// 'Class' internal values.
		Graphics_Buffer[0].Address		= (UBYTE*)(VRAM + 0x0000);
		Graphics_Buffer[0].Accessable	= TRUE;
		Graphics_Buffer[0].Width		= MODE4_WIDTH;
		Graphics_Buffer[0].Height		= MODE4_HEIGHT;
		Graphics_Buffer[0].MemSize		= MODE4_MEM_SIZE;
		Graphics_Buffer[0].Style		= BG_STYLE_MODE4;

		Graphics_Buffer[1].Address		= (UBYTE*)(VRAM + BG_BITMAP_MODES_VRAM_STEP_SIZE);
		Graphics_Buffer[1].Accessable	= TRUE;
		Graphics_Buffer[1].Width		= MODE4_WIDTH;
		Graphics_Buffer[1].Height		= MODE4_HEIGHT;
		Graphics_Buffer[1].MemSize		= MODE4_MEM_SIZE;
		Graphics_Buffer[1].Style		= BG_STYLE_MODE4;

		Graphics_Buffer[2].Address		= NULL;
		Graphics_Buffer[2].Accessable	= FALSE;
		Graphics_Buffer[3].Address		= NULL;
		Graphics_Buffer[3].Accessable	= FALSE;

		Graphics_ActiveScreen		= 1;	// Start by drawing to the back buffer.
//		Graphics_WorkingBuffer		= Graphics_Buffer[Graphics_ActiveScreen].Address;

		// Hardware modification.
		*(UHWORD*)REG_DISPCNT	= ((*(UHWORD*)REG_DISPCNT) & 0xFFF8) | 4;				// Mode 4.
		CLEAR_BIT_AT_ADDRESS(	REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_FRAME_BUFFER_BIT);// Select first frame buffer.
		CLEAR_BIT_AT_ADDRESS(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG0_BIT);			// Turn off BG0.
		CLEAR_BIT_AT_ADDRESS(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG1_BIT);			// Turn off BG1.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG2_BIT);			// Turn on BG2.
		CLEAR_BIT_AT_ADDRESS(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_BG3_BIT);			// Turn off BG3.
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_OAM_BIT);			// Turn on sprites.
		break;
//#endif // End 'GRAPHICS_SUPPORT_MODE_4'

//#ifdef GRAPHICS_SUPPORT_MODE_5
	case 5:
		// Not implemented
		break;
//#endif	// End '#ifdef GRAPHICS_SUPPORT_MODE_5'

	default:
		ERROR_PATH_TRAP("Attempt to set an unsupported graphics mode.")
		break;
	}
	Graphics_DisplayMode = _Mode;
}

// ----
// Enable or disable a BG. 
// Not all BGs are available in all modes
// 0 - off.
// 1 - on.
void	Graphics_SetBackground(INT	_BackgroundIndex, INT _State)
{
	if (_State)
	{
		SET_BIT_AT_ADDRESS	(REG_DISPCNT, UHWORD, (GRAPHICS_DISPLAY_BG0_BIT + _BackgroundIndex));
	}
	else
	{
		CLEAR_BIT_AT_ADDRESS(REG_DISPCNT, UHWORD, (GRAPHICS_DISPLAY_BG0_BIT + _BackgroundIndex));
	}
}

// ----
// Set Background Priority
void	Graphics_SetBackgroundPriority(INT	_BackgroundIndex, INT	_Priority)
{
	if (Graphics_DisplayMode > 2)	// No screen priorities in bitmap mode (you only see BG2).
		return;

	*(UHWORD*)BGCntRegs[_BackgroundIndex] = ((*(UHWORD*)BGCntRegs[_BackgroundIndex]) & 0xFFFC) | (_Priority & 0x03);
}

// ----
// Set Background Character	Base Block.
void	Graphics_SetBackgroundCharBaseBlock(INT	_BackgroundIndex, INT	_Base)
{
	if (	(Graphics_DisplayMode > 2) 
		&&	(_BackgroundIndex != 2))
		return;

	Graphics_Buffer[_BackgroundIndex].CharBase = _Base;
	*(UHWORD*)BGCntRegs[_BackgroundIndex]	= (*(UHWORD*)BGCntRegs[_BackgroundIndex] & 0xFFF3) | ((_Base & 0x03) << 2);
}

// ----
// Set Background Mosiac.
// 0 - off
// 1 - on
void	Graphics_SetBackgroundMosiac(INT	_BackgroundIndex, INT	_Mosiac)
{
	if (	(Graphics_DisplayMode > 2) 
		&&	(_BackgroundIndex != 2))
		return;

	*(UHWORD*)BGCntRegs[_BackgroundIndex]	= (*(UHWORD*)BGCntRegs[_BackgroundIndex] & 0xFFBF) | ((_Mosiac & 0x01) << 6);
}

// ----
// Set Background Colour Mode.
// 0 - for 16*16 colour palettes.
// 1 - for 1*256 colour palette.
void	Graphics_SetBackgroundColourMode(INT	_BackgroundIndex, INT	_ColourMode)
{
	if (Graphics_DisplayMode > 2)	// For bitmap modes the colour choice is entriely dependent on graphics mode. 
		return;

	*(UHWORD*)BGCntRegs[_BackgroundIndex]	= (*(UHWORD*)BGCntRegs[_BackgroundIndex] & 0xFF7F) | ((_ColourMode & 0x01) << 7);
}

// ----
// Set Background Screen Base Block.
// This function is only to be used when working with text 
// based modes - bitmap modes have fixed addresses.
// Values between 0-31.
void	Graphics_SetBackgroundScreenBaseBlock(INT	_BackgroundIndex, INT	_BaseBlock)
{
	if (	(Graphics_DisplayMode > 2) 
		&&	(_BackgroundIndex != 2))
	{
		Graphics_Buffer[_BackgroundIndex].Accessable	= FALSE;
		Graphics_Buffer[_BackgroundIndex].Address		= NULL;
		return;
	}

	*(UHWORD*)BGCntRegs[_BackgroundIndex]	= (*(UHWORD*)BGCntRegs[_BackgroundIndex] & 0xE0FF) | ((_BaseBlock & 0x1F) << 8);

	// Update our records.
	Graphics_Buffer[_BackgroundIndex].Accessable	= TRUE;
	Graphics_Buffer[_BackgroundIndex].Address		= (UBYTE*)(VRAM + BG_TEXT_MODES_VRAM_STEP_SIZE * _BaseBlock);
	
	// Enforce NULL on none accessable BGs.
	switch (Graphics_DisplayMode)
	{
	case 1:
		if (_BackgroundIndex == 3)
		{
			Graphics_Buffer[_BackgroundIndex].Accessable	= FALSE;
			Graphics_Buffer[_BackgroundIndex].Address		= NULL;
		}
		break;

	case 2:
		if (_BackgroundIndex <= 1)
		{
			Graphics_Buffer[_BackgroundIndex].Accessable	= FALSE;
			Graphics_Buffer[_BackgroundIndex].Address		= NULL;
		}
		break;
	default:
		// Don't care about all other cases.
		break;
	}
}

// ----
// Set Background Transparency / wrap.
// This function only effects BG2 and 3.
// 0 - transparent display.
// 1 - wraparound display.
void	Graphics_SetBackgroundTransparency(INT	_BackgroundIndex, INT	_Effect)
{
	*(UHWORD*)BGCntRegs[_BackgroundIndex]	= (*(UHWORD*)BGCntRegs[_BackgroundIndex] & 0xDFFF) | ((_Effect & 0x01) << 13);
}

// ----
// Set Background Screen Size.
// Values 0 - 3. 
void	Graphics_SetBackgroundScreenSize(INT	_BackgroundIndex, INT	_Size)
{
	if (Graphics_DisplayMode > 2)
		return;

	*(UHWORD*)BGCntRegs[_BackgroundIndex]	= (*(UHWORD*)BGCntRegs[_BackgroundIndex] & 0x3FFF) | ((_Size & 0x03) << 14);
}

// ----
// Swap surfaces
void	Graphics_SwapScreens()
{
	if (	(Graphics_DisplayMode == 4)
		||	(Graphics_DisplayMode == 5)) // Only modes 4 and 5 can be considered to have buffering capabilities.
	{
		TOGGLE_BIT_AT_ADDRESS(REG_DISPCNT, UHWORD, GRAPHICS_DISPLAY_FRAME_BUFFER_BIT);

		Graphics_ActiveScreen = 1 - Graphics_ActiveScreen;
//		Graphics_WorkingBuffer = Graphics_Buffer[Graphics_ActiveScreen].Address;
	}
}

// ----
// Offset a background.
// Note, values must be positive!!!
void	Graphics_OffsetBackground(INT	_BackgroundIndex,
								  INT	_X, 
								  INT	_Y)
{
	*(UHWORD*)BGXOffsetRegs[_BackgroundIndex]	= _X & 0x1FF;
	*(UHWORD*)BGYOffsetRegs[_BackgroundIndex]	= _Y & 0x1FF;
}

// ----
// Rotate / scale a background.
// Note, this function can only be applied to certain BGs in certain screen modes.
// This function can only be called during a vertical blank.
void	Graphics_RotateScaleBackground(	INT		_BackgroundIndex,
										INT		_XScale, 
										INT		_YScale,
										INT		_Rotation)
{
	SHWORD	bg_pa, bg_pb, bg_pc, bg_pd;
	SWORD	bg_start_x, bg_start_y;
	SHWORD	bg_pos_x, bg_pos_y;
	
	bg_pos_x = 0;
	bg_pos_y = 0;

	// Once the code works take these out to speed things up.
	if (Graphics_DisplayMode == 0)
		return;

	if (	(	(Graphics_DisplayMode	== 1) 
			||	(Graphics_DisplayMode	> 2))
		&&	(_BackgroundIndex		!= 2))
		return;

	if (	(Graphics_DisplayMode == 2) 
		&&	(_BackgroundIndex < 2))
		return;

	//  pa = cos(bg_rotate)*(1/bg_scale_x)
    bg_pa = fix_mul(_Cos(_Rotation), fix_inverse(_XScale));

	//  pb = sin(bg_rotate)*(1/bg_scale_x)
    bg_pb = fix_mul(_Sin(_Rotation), fix_inverse(_XScale));

	//  pc =-sin(bg_rotate)*(1/bg_scale_y)
    bg_pc = fix_mul(-_Sin(_Rotation), fix_inverse(_YScale));

	//  pd = cos(bg_rotate)*(1/bg_scale_y)
    bg_pd = fix_mul(_Cos(_Rotation), fix_inverse(_YScale));

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
	*(UHWORD*)BGXHRegs[_BackgroundIndex]	= (u16)(u32)((bg_start_x & 0x0fff0000)>>16);
	*(UHWORD*)BGXLRegs[_BackgroundIndex]	= (bg_start_x & 0xffff);

	// Y - High and Low.
	*(UHWORD*)BGYHRegs[_BackgroundIndex]	= (u16)(u32)((bg_start_y & 0x0fff0000)>>16);
	*(UHWORD*)BGYLRegs[_BackgroundIndex]	= (bg_start_y & 0xffff);
	
	*(UHWORD*)BGPARegs[_BackgroundIndex]	= (SHWORD)bg_pa;
	*(UHWORD*)BGPBRegs[_BackgroundIndex]	= (SHWORD)bg_pb;
	*(UHWORD*)BGPCRegs[_BackgroundIndex]	= (SHWORD)bg_pc;
	*(UHWORD*)BGPDRegs[_BackgroundIndex]	= (SHWORD)bg_pd;
}

// Not available if we're not planning to use some bitmap modes.
//#if	(defined GRAPHICS_SUPPORT_MODE_3) || (defined GRAPHICS_SUPPORT_MODE_4) || (defined GRAPHICS_SUPPORT_MODE_5)

// ----
// Draw a single pixel.
void	Graphics_DrawPixelXY(INT _X, INT _Y, COLOUR _Col)
{
	PUT_PIXEL_CORE_PAL8(_X, _Y, _Col.PaletteIndex);
}

// ----
// Draw a single pixel width line.
void	Graphics_DrawLineXYXY(	INT _X0, INT _Y0, 
								INT _X1, INT _Y1, 
								COLOUR _Col)
{
	INT		pixel_count;
	INT		X, Y, XdX, YdY;
	LONG	XInc, YInc;
	LONG	XCount, YCount;

	// Initialise variables.
	pixel_count		= max(abs((_X1 - _X0)), abs((_Y1 - _Y0)));
	
	X = _X1 - _X0;
	Y = _Y1 - _Y0;
	XInc			= (abs(X) << 16) / pixel_count;
	YInc			= (abs(Y) << 16) / pixel_count;
	XCount			= 0;
	YCount			= 0;
	X				= _X0;
	Y				= _Y0;

	XdX = 0;
	if ((_X1 - _X0) > 0)
		XdX = 1;
	else if ((_X1 - _X0) < 0)
		XdX = -1;

	YdY = 0;
	if ((_Y1 - _Y0) > 0)
		YdY = 1;
	else if ((_Y1 - _Y0) < 0)
		YdY = -1;

	if (!(Graphics_Buffer[Graphics_ActiveScreen].Style & BG_STYLE_BITMAP))
		return;

	if (Graphics_Buffer[Graphics_ActiveScreen].Style & BG_STYLE_MODE4)
	{
		while (pixel_count > 0)
		{
			PUT_PIXEL_CORE_PAL8(X, Y, _Col.PaletteIndex);
			XCount += XInc;
			YCount += YInc;
			while (XCount >> 16)
			{
				X += XdX;
				XCount -= (1 << 16);
			}
			while (YCount >> 16)
			{
				Y += YdY;
				YCount -= (1 << 16);
			}

			pixel_count--;
		}
	}
	else
	{
		while (pixel_count > 0)
		{
			PUT_PIXEL_CORE_PAL16(X, Y, _Col.RGBDirect);
			XCount += XInc;
			YCount += YInc;
			while (XCount >> 16)
			{
				X += XdX;
				XCount -= (1 << 16);
			}
			while (YCount >> 16)
			{
				Y = YdY;
				YCount -= (1 << 16);
			}

			pixel_count--;
		}
	}
}

// ----
// Draw internally referenced triangle array.
void	Graphics_DrawTriangleArray()
{
	INT	i;

	// Loop all triangles.
//	for (i = 0; i < Graphics_TriCount; i++)
	i = 0;
	{
	//	Debug_ErrorBar(2);
		/*
		(Graphics_DrawTriCode)(	(Graphics_TriPointArray + 3 * i),
								(Graphics_TriColourArray + i));
		*/

		Graphics_DrawFilledTriangle((Graphics_TriPointArray + 3 * i),
									(Graphics_TriColourArray + i));
	}
	Graphics_TriCount = 0;
}

// ----
// Draw a filled triangle
void	Graphics_DrawFilledTriangle(POINT*	_TriPointArray,
									COLOUR*	_Col)
{
	INT		X0, X1, Y;
	INT		dxB, dxC;
	LONG	countB, countC;
	INT		Bpp, Cpp;
	
	INT i;
	UBYTE*	Addr;
	//UBYTE	PalIndex;
	UHWORD	tempw, tempcol;
	INT		_X0, _X1, _Y;
	POINT	A, B, C, temp;

	// Plan of action.
	// Locate top co-ordiante.
	// Calculate dx values to get to both end points - one of which will be recalculated as soon as the next highest point is reached.
	// Draw lines between two calculated end points.

//tri_again:
//	if (!Graphics_TriCount)
//		return;
	while(Graphics_TriCount)
	{

		A = *(_TriPointArray + 0);
		B = *(_TriPointArray + 1);
		C = *(_TriPointArray + 2);

		// Sort points A, B, C into ascending order.
		if (B.Y < A.Y)
		{
			temp = B;
			B = A;
			A = temp;
		}

		if (C.Y < A.Y)
		{
			temp = C;
			C = A;
			A = temp;
		}

		if (C.Y < B.Y)
		{
			temp = B;
			B = C;
			C = temp;
		}

		/*
		if (B.X > C.X)
		{
			temp = B;
			B = C;
			C = temp;
		}*/

		// Assign start values.
		X0 = A.X;
		X1 = A.X;

		if (!(B.Y - A.Y))
		{
			dxB = 0;
			X0 = B.X;
		}
		else
		{
			dxB	= ((B.X - A.X) << 8) / (B.Y - A.Y); 
		}

		if (!(C.Y - A.Y))
		{
			dxC = 0;
			X1 = C.X;
		}
		else
		{
			dxC	= ((C.X - A.X) << 8) / (C.Y - A.Y);	
		}
		countB = 0;
		countC = 0;

		if (dxB < 0)
			Bpp = -1;
		else
			Bpp = 1;
		if (dxC < 0)
			Cpp = -1;
		else
			Cpp = 1;

		dxB = abs(dxB);
		dxC = abs(dxC);

		tempcol = (_Col->PaletteIndex << 8) | _Col->PaletteIndex;

		// Loop through all lines from top to bottom of triangle.
		for (Y = A.Y; Y < B.Y; Y++)
		{
			/*
			// Copy loop structure and take this out - to use in second case.
			if (Y == B.Y)
			{
				// Y is at point B, thus recalculate gradient to point C.
				if (!(C.Y - B.Y))
				{
					dxB	= 0;
					X0	= C.X;
				}
				else
				{
					dxB	= ((C.X - B.X) << 8) / (C.Y - B.Y);	
					X0	= B.X;

					if (dxB < 0)
						Bpp = -1;
					else
						Bpp = 1;

					dxB = abs(dxB);
				}

				countB	= 0;
			}*/

			// Increment fractional counters. 
			// Modify horizonatal line start / end accordingly.
			countB += dxB;
			while (countB >= (1 << 8))
			{
				X0 += Bpp;
				countB -= 1 << 8;
			}
		
			countC += dxC;
			while (countC >= (1 << 8))
			{
				X1 += Cpp;
				countC -= 1 << 8;
			}
		
			// Draw a horizontal line.
			//Graphics_DrawHorizontal(X0, X1, Y, _Col);

			// Assign values for rendering code.
			_Y = Y;
			if (X0 > X1)
			{
				_X0 = X1;
				//_X1 = X0;
				tempw = X0 - X1;
			}
			else
			{
				_X0 = X0;
				//_X1 = X1;
				tempw = X1 - X0;
			}
	/*
			// Clipping - this does have an impact. Might be better to make this code quick, and sort what you send it.
			if (_X0 < 0)
				_X0 = 0;
			if (_X1 > 239)
				_X1 = 239;
			if (_Y < 0)
				continue;
			if (_Y > 159)
				break;
	*/
			//tempw = _X1 - _X0;
			//if (X0 > X1)
			//	Debug_ErrorBar(1);

			if (!tempw)
				continue;
			
			if (tempw & 1)	// 16bit writes.
				tempw++;
			
			// If I knew the winding order I could take part of this calculation out of the loop.
			Addr = Graphics_Buffer[Graphics_ActiveScreen].Address + (Graphics_Buffer[Graphics_ActiveScreen].Width * _Y + _X0); 
			if ((LONG)Addr & 1)
				Addr--;
		
			// Draw the freaking line.
			//DmaClear(3, tempcol, Addr, tempw, 16);
			DmaCopy(3, Graphics_DrawTriBuffer, Addr, tempw, 16);
		}

		// SECOND SET


		// Y is at point B, thus recalculate gradient to point C.
		if (!(C.Y - B.Y))
		{
			dxB	= 0;
			X0	= C.X;
		}
		else
		{
			dxB	= ((C.X - B.X) << 8) / (C.Y - B.Y);	
			X0	= B.X;

			if (dxB < 0)
				Bpp = -1;
			else
				Bpp = 1;

			dxB = abs(dxB);
		}
		countB	= 0;


		// Loop through all lines from top to bottom of triangle.
		for (Y = B.Y; Y < C.Y; Y++)
		{
			// Increment fractional counters. 
			// Modify horizonatal line start / end accordingly.
			countB += dxB;
			while (countB >= (1 << 8))
			{
				X0 += Bpp;
				countB -= 1 << 8;
			}
		
			countC += dxC;
			while (countC >= (1 << 8))
			{
				X1 += Cpp;
				countC -= 1 << 8;
			}
		
			// Draw a horizontal line.
			//Graphics_DrawHorizontal(X0, X1, Y, _Col);
		
			_Y = Y;
			if (X0 > X1)
			{
				_X0 = X1;
				//_X1 = X0;
				tempw = X0 - X1;
			}
			else
			{
				_X0 = X0;
				//_X1 = X1;
				tempw = X1 - X0;
			}
	/*
			// Clipping - this does have an impact. Might be better to make this code quick, and sort what you send it.
			if (_X0 < 0)
				_X0 = 0;
			if (_X1 > 239)
				_X1 = 239;
			if (_Y < 0)
				continue;
			if (_Y > 159)
				break;
	*/
			
			if (!tempw)
				continue;
			
			if (tempw & 1)	// 16bit writes.
				tempw++;
			
			// If I knew the winding order I could take part of this calculation out of the loop.
			Addr = Graphics_Buffer[Graphics_ActiveScreen].Address + (Graphics_Buffer[Graphics_ActiveScreen].Width * _Y + _X0); 
			if ((LONG)Addr & 1)
				Addr--;
		
			// Draw the freaking line.
			//DmaClear(3, tempcol, Addr, tempw, 16);
			DmaCopy(3, Graphics_DrawTriBuffer, Addr, tempw, 16);
		}

		_TriPointArray += 3;
		_Col++;
		Graphics_TriCount--;
	}
	//goto tri_again;
}

// ----
// Draw a horizontal line of pixels.
void	Graphics_DrawHorizontal(INT _X0, INT _X1, INT _Y, COLOUR* _Col)
{
	INT i;
	UBYTE*	Addr;
	UBYTE	PalIndex;
	UHWORD	tempw, tempcol;

	
	PalIndex = _Col->PaletteIndex;
	if (_X0 > _X1)
	{
		i = _X0;
		_X0 = _X1;
		_X1 = i;
	}

	Addr = Graphics_Buffer[Graphics_ActiveScreen].Address + (Graphics_Buffer[Graphics_ActiveScreen].Width * _Y + _X0); 
	

	if ((LONG)Addr & 1)
		Addr--;
	
	tempw = (_X1 - _X0);
	if (tempw & 1)	// 16bit writes.
		tempw++;
	if (!tempw)
		return;

	tempcol = (PalIndex << 8) | PalIndex;
	DmaClear(3, tempcol, Addr, tempw, 16);
}

// ----
void	Graphics_ClipPolys()
{
}

// ----
// Clear the screen.
void	Graphics_ClearScreen(COLOUR	_Col)
{
	// Use DMA 3 to fill the specified buffer with a given palette index (colour).
	DmaClear(	3, 
				((_Col.PaletteIndex << 8) | _Col.PaletteIndex), 
				Graphics_Buffer[Graphics_ActiveScreen].Address, 
				Graphics_Buffer[Graphics_ActiveScreen].MemSize, 
				16);
}

//#endif	// End '#if	defined GRAPHICS_SUPPORT_MODE_3 || defined GRAPHICS_SUPPORT_MODE_4 || defined GRAPHICS_SUPPORT_MODE_5'

// ----
// Note for palette functions.
// In all cases I have assumed that the palette is 256 items in size.

// ----
// Find the closest match to a colour from the currently loaded palette.
UBYTE	Graphics_GetIndexFromPalette(UBYTE _R, UBYTE _G, UBYTE _B)
{
	UBYTE	i, ret = 0;
	UBYTE	RD, GD, BD;	// Difference.
	UBYTE	RW, GW, BW;	// Working.

	// Start from one as entry zero is always transparent.
	Graphics_GetPaletteColour(1, &RD, &GD, &BD); 
	RD = abs(RD - _R);
	GD = abs(GD - _G);
	BD = abs(BD - _B);

	for (i = 1; i < 256; i++) // Assuming mode 4, or at least, a 256 colour palette.
	{
		Graphics_GetPaletteColour(i, &RW, &GW, &BW);
		if (	(abs(RW - _R) <= RD)
			&&	(abs(GW - _G) <= GD)
			&&	(abs(BW - _B) <= BD))
		{
			ret = i;
			RD = abs(RW - _R);
			GD = abs(GW - _G);
			BD = abs(BW - _B);

			if (RD == GD == BD == 0)
				return ret;	// Early exit for a dead match.
		}
	}
	return ret;
}

// ----
// Modify a palette entry.
void	Graphics_SetPaletteColour(UBYTE	_Index, UBYTE _R, UBYTE _G, UBYTE _B)
{
	*((UHWORD*)PLTT + _Index)= (UHWORD)(((_B >> 3) << PLTT_BLUE_SHIFT) 
									| 	((_G >> 3) << PLTT_GREEN_SHIFT)
									|	((_R >> 3) << PLTT_RED_SHIFT));
}

// ----
// Find out what colour we are looking at. 
// The usefulness of this function is questionable - thus 
// remove if the function isn't used.
void	Graphics_GetPaletteColour(UBYTE	_Index, UBYTE *_R, UBYTE *_G, UBYTE *_B)
{
	UHWORD value = *((UHWORD*)PLTT + _Index);

	*_R = ((value & PLTT_RED_MASK) >> PLTT_RED_SHIFT) << 3;
	*_G = ((value & PLTT_GREEN_MASK) >> PLTT_GREEN_SHIFT) << 3;
	*_B = ((value & PLTT_BLUE_MASK) >> PLTT_BLUE_SHIFT) << 3;
}


// ----
// Frees a particular object.
void	Graphics_FreeObject(UHWORD _ID)
{
	UHWORD	*DelObjPtr, *MoveObjPtr;

	if (_ID >= Graphics_NumberOfAllocatedObjects)
		return;

	DelObjPtr =		(UHWORD*)(OAM + 2 * _ID);
	MoveObjPtr =	(UHWORD*)(OAM + 2 * (Graphics_NumberOfAllocatedObjects - 1));

	*(UHWORD*)(DelObjPtr++) = *(UHWORD*)(MoveObjPtr);	// Attribute 0
	*(UHWORD*)(DelObjPtr++) = *(UHWORD*)(MoveObjPtr);	// Attribute 1
	*(UHWORD*)(DelObjPtr++) = *(UHWORD*)(MoveObjPtr);	// Attribute 2

	Graphics_NumberOfAllocatedObjects--;
}

// ----
// Frees all objects
void	Graphics_FreeAllObjects()
{
	UHWORD	*ObjPtr;

	ObjPtr = (UHWORD*)OAM;
	for (;Graphics_NumberOfAllocatedObjects--;)
	{
		*(UHWORD*)(ObjPtr++) = 0;	// Attribute 0
		*(UHWORD*)(ObjPtr++) = 0;	// Attribute 1
		*(UHWORD*)(ObjPtr++) = 0;	// Attribute 2
		ObjPtr++;
	}

	Graphics_NumberOfAllocatedObjects = 0;
}

// ----
// Allocate a Object resource - the return value is the ID
// for the object resource, use this to set/modify an
// object's attributes.
// A return value equal to or greater than 1024 indicates failure.
UHWORD	Graphics_AllocateObjectSpace()
{
	if (Graphics_NumberOfAllocatedObjects >= 128)
		return 1024;	// Error code.

	return Graphics_NumberOfAllocatedObjects++;
}

// ----
// Simpliar to 'Graphics_AllocateObjectSpace', but allows all 
// properties to be set in on go.
// Returns a value >= 1024 in the case of an error.
UHWORD	Graphics_AddObject(UHWORD	_ObjAttr0, 
						   UHWORD	_ObjAttr1, 
						   UHWORD	_ObjAttr2)
{
	UHWORD	*OAMPtr;

	if (Graphics_NumberOfAllocatedObjects >= 128)
		return 1024;	// Error code.

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * Graphics_NumberOfAllocatedObjects);
	*(UHWORD*)OAMPtr++ = _ObjAttr0;
	*(UHWORD*)OAMPtr++ = _ObjAttr1;
	*(UHWORD*)OAMPtr++ = _ObjAttr2;

	return Graphics_NumberOfAllocatedObjects++;
}

// ----
// Similar to the function above, but allows one to specify
// each and every attribute of an object when adding it to 
// the list of objects
UHWORD	Graphics_AddObjectDefine(	// Character base address select.
									UHWORD	_CharacterBase,

									// Object shape and size.
									UBYTE	_ObjectSize,
									UBYTE	_ObjectShape,
									
									// Screen co-ords.
									UHWORD	_X, 
									UBYTE	_Y,
									UBYTE	_Priority,

									// Colour
									BOOL	_Colour,
									UBYTE	_Palette,

									// Effects
									UBYTE	_ObjectMode,
									BOOL	_Mosaic,
									BOOL	_HorizontalFlip,
									BOOL	_VerticalFlip,
									
									// Rotation and scaling.
									BOOL	_RotScaleState,
									BOOL	_RotScaleDoubleSize,
									UBYTE	_RotScaleParam)
{
	UHWORD	*OAMPtr;

	if (Graphics_NumberOfAllocatedObjects >= 128)
		return 1024;	// Error code.

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * Graphics_NumberOfAllocatedObjects);

	// Process attribute 0(zero) stuff first.
	*(UHWORD*)OAMPtr++ =	((0x03 & _ObjectShape) << 14)		// Bits 14 and 15.	[Shape]
						|	((0x01 & _Colour) << 13)			// Bit 13.			[Colour]
						|	((0x01 & _Mosaic) << 12)			// Bit 12.			[Mosaic]
						|	((0x03 & _ObjectMode) << 10)		// Bits 10 and 11.	[ObjectMode]
						|	((0x01 & _RotScaleDoubleSize) << 9)	// Bit 9.			[RotScaleDoubleSize]
						|	((0x01 & _RotScaleState) << 8)		// Bit 8.			[RotScaleState]
						|	((0xFF & _Y) << 0);					// Bits 0-7.		[Y].

	// Process attribute 1(one).
	*(UHWORD*)OAMPtr++ =	((0x03 & _ObjectSize) << 14)		// Bits 14 and 15.	[Size]
						|	((0x01 & _VerticalFlip) << 13)		// Bit 13.			[VerticalFlip]
						|	((0x01 & _HorizontalFlip) << 12)	// Bit 12.			[HorizontalFlip]
						|	((0x1F & _RotScaleParam) << 9)		// Bits 9-13.		[RotScaleParam]
						|	((0x01FF & _X) << 0);				// Bits 0-8.		[X].

	// Process attribute 2(two).
	*(UHWORD*)OAMPtr =		((0x0F & _Palette) << 12)			// Bits 12-15.		[Palette]
						|	((0x03 & _Priority) << 10)			// Bit 13.			[Priority]
						|	((0x03FF & _CharacterBase) << 0);	// Bits 0-8.		[CharacterBase].

	return Graphics_NumberOfAllocatedObjects++;
}

// ----
// Allow the setting of all the possible attributes for an object.
void	Graphics_SetObjectXY				(UHWORD _ID, UHWORD	_X, UBYTE _Y)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID);	// 4 * sizeof(UHWORD) * _ID.
	*(UHWORD*)OAMPtr++	|= (0x00FF & _Y);
	*(UHWORD*)OAMPtr	|= (0x01FF & _X);
}

// ----
void	Graphics_SetObjectSetRotScaleState	(UHWORD _ID, BOOL	_RotScalingState)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID);	// 4 * sizeof(UHWORD) * _ID.
	if (_RotScalingState)
		SET_BIT_AT_ADDRESS(OAMPtr, UHWORD, 8)		// Bit 8 - rotation scaling on/off [ON]
	else
		CLEAR_BIT_AT_ADDRESS(OAMPtr, UHWORD, 8)		// Bit 8 - rotation scaling on/off [OFF]
}

// ----
void	Graphics_SetObjectSetDoubleSize		(UHWORD _ID, BOOL	_RotScalingDoubleSize)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID);	// 4 * sizeof(UHWORD) * _ID.
	if (_RotScalingDoubleSize)
		SET_BIT_AT_ADDRESS(OAMPtr, UHWORD, 9)		// Bit 9 - rotation scaling double-size flag on/off [ON]
	else
		CLEAR_BIT_AT_ADDRESS(OAMPtr, UHWORD, 9)		// Bit 9 - rotation scaling double-size flag on/off [OFF]
}

// ----
// See page 60 of AGB programming manual for info.
void	Graphics_SetObjectMode				(UHWORD _ID, UBYTE	_Mode)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID);	// 4 * sizeof(UHWORD) * _ID.
	*(UHWORD*)OAMPtr	|= ((0x03 & _Mode) << 10);
}

// ----
void	Graphics_SetObjectMosiac			(UHWORD _ID, BOOL	_Mosaic)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID);	// 4 * sizeof(UHWORD) * _ID.
	if (_Mosaic)
		SET_BIT_AT_ADDRESS(OAMPtr, UHWORD, 12)		// Bit 12 - mosaic on/off [ON]
	else
		CLEAR_BIT_AT_ADDRESS(OAMPtr, UHWORD, 12)	// Bit 12 - mosaic on/off [OFF]
}

// ----
// 0 = 16 colour. 1 = 256 colour.
void	Graphics_SetObjectColourMode		(UHWORD _ID, BOOL	_ColourMode)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID);	// 4 * sizeof(UHWORD) * _ID.
	if (_ColourMode)
		SET_BIT_AT_ADDRESS(OAMPtr, UHWORD, 13)		// Bit 13 - colour depth [256]
	else
		CLEAR_BIT_AT_ADDRESS(OAMPtr, UHWORD, 13)	// Bit 13 - colour depth [16]
}

// ----
// 0 = square. 1 = horizontal. 2 = vertical.
void	Graphics_SetObjectShape				(UHWORD _ID, UBYTE	_Shape)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID);	// 4 * sizeof(UHWORD) * _ID.
	*(UHWORD*)OAMPtr	|= ((0x03 & _Shape) << 14);
}

// ----
// See page 64 of AGB programming manual for info.
void	Graphics_SetObjectRotationScaling	(UHWORD _ID, UBYTE	_RotScale)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID + 2);	// 4 * sizeof(UHWORD) * _ID + sizeof(UHWORD).
	*(UHWORD*)OAMPtr	|= ((0x1F & _RotScale) << 9);
}

// ----
// See page 63 of AGB programming manual for info.
void	Graphics_SetObjectSize				(UHWORD _ID, UBYTE	_Size)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID + 2);	// 4 * sizeof(UHWORD) * _ID + sizeof(UHWORD).
	*(UHWORD*)OAMPtr	|= ((0x03 & _Size) << 14);
}

// ----
void	Graphics_SetObjectFlipHorizontally	(UHWORD _ID, BOOL	_State)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID + 2);	// 4 * sizeof(UHWORD) * _ID + sizeof(UHWORD).
	if (_State)
		SET_BIT_AT_ADDRESS(OAMPtr, UHWORD, 12)		// Bit 12 - horizontal flip [ON]
	else
		CLEAR_BIT_AT_ADDRESS(OAMPtr, UHWORD, 12)	// Bit 12 - horizontal flip [OFF]
}

// ----
void	Graphics_SetObjectFlipVertically	(UHWORD _ID, BOOL	_State)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID + 2);	// 4 * sizeof(UHWORD) * _ID + sizeof(UHWORD).
	if (_State)
		SET_BIT_AT_ADDRESS(OAMPtr, UHWORD, 13)		// Bit 13 - vertical flip [ON]
	else
		CLEAR_BIT_AT_ADDRESS(OAMPtr, UHWORD, 13)	// Bit 13 - vertical flip [OFF]
}

// ----
void	Graphics_SetObjectPalette			(UHWORD _ID, UBYTE	_Palette)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID + 4);	// 4 * sizeof(UHWORD) * _ID + 2 * sizeof(UHWORD).
	*(UHWORD*)OAMPtr	|= ((0x0F & _Palette) << 12);
}

// ----
void	Graphics_SetObjectPriority			(UHWORD _ID, UHWORD	_Priority)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID + 4);	// 4 * sizeof(UHWORD) * _ID + 2 * sizeof(UHWORD).
	*(UHWORD*)OAMPtr	|= ((0x03 & _Priority) << 10);
}

// ----
void	Graphics_SetObjectCharacterName		(UHWORD _ID, UHWORD	_CharacterName)
{
	UHWORD	*OAMPtr;

	OAMPtr = (UHWORD*)(OAM + 4 * 2 * _ID + 4);	// 4 * sizeof(UHWORD) * _ID + 2 * sizeof(UHWORD).
	*(UHWORD*)OAMPtr	|= ((0x03FF & _CharacterName) << 0);
}

