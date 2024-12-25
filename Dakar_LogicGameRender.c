// FILE:		Dakar_LogicGameRender.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// COMMENTS:	This file contains the Dakar in-game rendering code.

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
#include	"Vector.h"

INT line;
INT	liner;
INT	gg, fps;

extern BOOL	method;

// ----
// This function is called when a verticle interrupt occurs.
// This is when we have time to process game code - and we 
// probably won't have a lot of that either. Therefore, this
// function will probably have to be converted to assembly.
void	Dakar_GameVerticalBlank()
{
#if 1
	Interrupts_Check	|= V_BLANK_INTR_FLAG;
	*(VUHWORD*)REG_IF	|= V_BLANK_INTR_FLAG;
	fps++;

	// Voxel technology.
	

//	memset(Graphics_Buffer[2].Address, jj, 240 * 160);
//	jj++;
//	jj &= 0xFF;

#else
	// this is all no voxel - flat plain crap.

#if 1
	SHWORD	bg_pa, bg_pb, bg_pc, bg_pd;
	SHWORD	x0, y0;	// Centre of rotation.
	SHWORD	x1, y1;	// Co-ord before rotation.
	SWORD	x2, y2;	// Top-left point.
	SHWORD	x1mx0, y1my0;

	SHWORD	_Rotation, _XScale, _YScale;

	Interrupts_Check	|= V_BLANK_INTR_FLAG;
	*(VUHWORD*)REG_IF	|= V_BLANK_INTR_FLAG;
	line = 0;
#endif

	liner = 0;
	line = 1;// + jj;
//	gg++;
//	gg &= 0xFF;

	jj++;
	if (jj > 80)
	{
		// Copy memory, and update top of map.
		// DmaCopy(3, VRAM + 2048 * Graphics_Buffer[ Work halted here for voxel test.

		// And reset counter
		jj = 1;
	}

#if 1
	_Rotation	= 0;//gg;
	_XScale		= 1;//0x100 + line;
	_YScale		= 1;//0x100 + line;

	//  pa = cos(bg_rotate)*(1/bg_scale_x)
    bg_pa = fix_mul(_Cos(_Rotation), fix_inverse(_XScale));

	//  pb = sin(bg_rotate)*(1/bg_scale_x)
    bg_pb = 0;//fix_mul(_Sin(_Rotation), fix_inverse(_XScale));

	//  pc =-sin(bg_rotate)*(1/bg_scale_y)
    bg_pc = 0;//fix_mul(-_Sin(_Rotation), fix_inverse(_YScale));

	//  pd = cos(bg_rotate)*(1/bg_scale_y)
    bg_pd = fix_mul(_Cos(_Rotation), fix_inverse(_YScale));

	//  Set starting point for reference

	//  120-bg_pos_x in the first line is for 
	// adjustment because bg_pos_x = 0 is center of screen. 
	//  Lower 2 lines are for matrix calculation.
	//  Assume center of rotation/scaling as center of screen 

/*	bg_start_x = ((120-bg_pos_x)<<8)
	- ( bg_pa * 120 )
	- ( bg_pb * 80 );
    bg_start_y = ((120-bg_pos_y)<<8)
	- ( bg_pc * 120 )
	- ( bg_pd * 80 );
*/
	//bg_start_x = ((240-bg_pos_x)<<8)	- ( bg_pa * 240)	- ( bg_pb * 120);
    //bg_start_y = ((120-bg_pos_y)<<8)	- ( bg_pc * 120)	- ( bg_pd * 120);

	// Centre of rotation.
	x0 = (240 >> 1);
	y0 = (160 >> 1);

	// Start point.
	x1 = (240 - 256) / 2;
	y1 = (160 - 256) / 2;

	
	// End point
	/*
	x2 =	(	((bg_pa * ((x1 - x0) << 8)) >> 8)	// now in 1.7.8
			+	((bg_pb * ((y1 - y0) << 8)) >> 8)
			+	(x0 << 8));

	y2 =	(	((bg_pc * ((x1 - x0) << 8)) >> 8)
			+	((bg_pd * ((y1 - y0) << 8)) >> 8)
			+	(y0 << 8));
	*/
	
	///*
	x1mx0	= (x1 - x0) * 256;
	y1my0	= (y1 - y0) * 256;
	x2 =	(	fix_mul(bg_pa, x1mx0)
			+	fix_mul(bg_pb, y1my0)
			+	(x0 * 256));

	y2 =	(	((bg_pc * x1mx0) / 256)
			+	((bg_pd * y1my0) / 256)
			+	(y0 * 256));
	//*/

	*(UHWORD*)REG_BG2X_H	= (u16)(u32)((x2 & 0x0fff0000)>>16);
	*(UHWORD*)REG_BG2X_L	= (x2 & 0xffff);
	*(UHWORD*)REG_BG2Y_H	= (u16)(u32)((y2 & 0x0fff0000)>>16);
	*(UHWORD*)REG_BG2Y_L	= (y2 & 0xffff);

	*(UHWORD*)REG_BG2PA		= (SHWORD)bg_pa;
	*(UHWORD*)REG_BG2PB		= (SHWORD)bg_pb;
	*(UHWORD*)REG_BG2PC		= (SHWORD)bg_pc;
	*(UHWORD*)REG_BG2PD		= (SHWORD)bg_pd;
#endif

	x2 = 120 << 8;
	y2 = 0;//256 << 8;

	*(UHWORD*)REG_BG2X_H	= (u16)(u32)((x2 & 0x0fff0000)>>16);
	*(UHWORD*)REG_BG2X_L	= (x2 & 0xffff);
	*(UHWORD*)REG_BG2Y_H	= (u16)(u32)((y2 & 0x0fff0000)>>16);
	*(UHWORD*)REG_BG2Y_L	= (y2 & 0xffff);
#endif
}

// ----
// In-game horizontal blank routines.
// This will have to be assembly I feel.
void	Dakar_GameHorizontalBlank()
{
#if 0
	
	INT		_BackgroundIndex, _XScale, _YScale, _Rotation;
	SHWORD	bg_pa, bg_pb, bg_pc, bg_pd;
	SWORD	bg_start_x, bg_start_y;
	SHWORD	bg_pos_x, bg_pos_y;
	
	line++;
//	if (line < 60)
//		return;

//	if ((line > 110) && (line % 2))
//		return;

	_BackgroundIndex	= 2;
	_XScale				= 0x000 + 20 * max(5, (line - 60));
	_YScale				= 0x000 + 20 * max(5, (line - 60));
	_Rotation			= 0;
	
	bg_pos_x = 0;
	bg_pos_y = jj - 90;

#if 0 // Work on hills, but not paying off too well.
	if ((line > 70) && (line < 100))
	{
		_XScale				= 0x000 + 20 * max(5, (line - 60)) + (100 - line);
		_YScale				= 0x000 + 20 * max(5, (line - 60)) + (100 - line);
	}
#endif

	//  pa = cos(bg_rotate)*(1/bg_scale_x)
    bg_pa = fix_mul(_Cos(_Rotation), fix_inverse(_XScale));

	//  pb = sin(bg_rotate)*(1/bg_scale_x)
    bg_pb = 0;//fix_mul(_Sin(_Rotation), fix_inverse(_XScale));

	//  pc =-sin(bg_rotate)*(1/bg_scale_y)
    bg_pc = 0;//fix_mul(-_Sin(_Rotation), fix_inverse(_YScale));

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

	//Graphics_RotateScaleBackground(2, 0x100 + 2 * line, 0x100 + 3 * line, 0);
#endif
}


// Write to a sequentially ordered 256 colour tile map (30 tiles
// per row, and a gap of two, when working on a 32x32 tile map. 
// The bottom two rows can not be addressed, as there are 
// insufficient tiles - would need 60 more).
#define	GRAPHICS_PUTPIXELVIALINEARTILEMAP(x, y, col)	\
*(UBYTE*)(BG_VRAM + 2 * 16384							\
		+ ((64 * 30) * (y / 8))							\
		+ (8 * (y % 8))									\
		+ (64 * (x >> 3))								\
		+ (x % 8)										\
		) = col;										// The colour.

/* Test code for the macro above.
	// ----
	// Test implementation of the above idea.

	BlockAddress	= Graphics_Buffer[2].Address;
	for (i = 0; i < 1024; i++)
	{
		*(UHWORD*)BlockAddress = i;
		BlockAddress += 2;

		if (!(i % 30))
			BlockAddress += 4;
	}

	// Fill the display with 
	for (i = 0; i < 240; i++)	// Scan lines - note only half the actually display width. I'm going to render all voxels as two pixels wide, at least for now.
	{
		//BlockAddress	= BG_VRAM + 2 * 16384 + i; //Graphics_Buffer[2].CharBase
		//ReadAddr		= BG_VRAM + 1 * 16384 + i;

		for (j = 0; j < 160; j++)
		{
			GRAPHICS_PUTPIXELVIALINEARTILEMAP(i, j, i);

			// *BlockAddress = *ReadAddr;
			
			// Ready for next loop.
			//BlockAddress += 8;
			//ReadAddr += 8;
		}
	}
*/

// ----
// Copy one map tile from ROM into RAM.
void	Dakar_CopyRomTileToRam(INT	_SplineIndex, INT _DestBlock)
{
	INT		y;
	UBYTE	*HeightSource, *HeightDest;
	USHORT	*ColourSource, *ColourDest;

	// Dakar_TileHeightArray will be an array of 32 * 32 bytes of height map daa.
	// Dakar_TrackArrayPointer is a pointer to the spline information, making up the track.
	// Dakar_TrackPosition is where the car is down that list.
	HeightSource = &Dakar_TileHeightArray[*(UBYTE*)(Dakar_TrackArrayPointer + (_SplineIndex * HEIGHT_TILE_SIZE))];
	HeightDest =	Dakar_GraphicsMapHeight 
				+	(_DestBlock & 1) * HEIGHT_TILE_WIDTH
				+	(_DestBlock >> 1) * HEIGHT_TILE_SIZE;

	// Can't copy an entire tile at a time as the end source is wider than the source.
	// So we do it line by line (all 32 of them).
	for (y = 0; y < HEIGHT_TILE_HEIGHT; y++)
	{
		DmaCopy(3,					// DMA 3
				HeightSource,		// The source height tile from ROM
				HeightDest,			// My (are) specific little rendering block.
				HEIGHT_TILE_WIDTH,	// 32 bytes.
				32);				// 32 bit bus (assuming that it is in CPURAM).

		// Next line.
		HeightSource	+= HEIGHT_TILE_WIDTH;
		HeightDest		+= HEIGHT_TILE_WIDTH << 1;
	}

	// Colour map.
	ColourSource = &Dakar_TileColourArray[*(UBYTE*)(Dakar_TrackArrayPointer + (_SplineIndex * COLOUR_TILE_SIZE))];
	ColourDest =	Dakar_GraphicsMapColour 
				+	(_DestBlock & 1) * COLOUR_TILE_WIDTH
				+	(_DestBlock >> 1) * COLOUR_TILE_SIZE;

	for (y = 0; y < COLOUR_TILE_HEIGHT; y++)
	{
		DmaCopy(3,					// DMA 3
				ColourSource,		// The source colour tile from ROM
				ColourDest,			// My (are) specific little rendering block.
				COLOUR_TILE_WIDTH,	// 32 bytes.
				32);				// 32 bit bus (assuming that it is in CPURAM).

		// Next line.
		ColourSource	+= COLOUR_TILE_WIDTH;		
		ColourDest		+= COLOUR_TILE_WIDTH << 1;
	}
}

// ----
void	Dakar_MoveMapRegion(UBYTE	_SourceBlock, 
							UBYTE	_DestBlock)
{
	INT		y;
	UBYTE	*HeightSource, *HeightDest;
	USHORT	*ColourSource, *ColourDest;

	// Calculate source and dest addresses.
	HeightSource =	Dakar_GraphicsMapHeight 
					+	(_SourceBlock & 1) * HEIGHT_TILE_WIDTH
					+	(_SourceBlock >> 1) * HEIGHT_TILE_SIZE;

	HeightDest =	Dakar_GraphicsMapHeight 
				+	(_DestBlock & 1) * HEIGHT_TILE_WIDTH
				+	(_DestBlock >> 1) * HEIGHT_TILE_SIZE;

	// Copy each of the 32 lines.
	for (y = 0; y < HEIGHT_TILE_HEIGHT; y++)
	{
		DmaCopy(3,					// DMA 3
				HeightSource,		// The source height tile from ROM
				HeightDest,			// My (are) specific little rendering block.
				HEIGHT_TILE_WIDTH,	// 32 bytes.
				32);				// 32 bit bus (assuming that it is in CPURAM).

		// Next line.
		HeightSource	+= HEIGHT_TILE_WIDTH << 1;
		HeightDest		+= HEIGHT_TILE_WIDTH << 1;
	}

	// Colour map.
	ColourSource =		Dakar_GraphicsMapColour 
					+	(_DestBlock & 1) * COLOUR_TILE_WIDTH
					+	(_DestBlock >> 1) * COLOUR_TILE_SIZE;

	ColourDest =	Dakar_GraphicsMapColour 
				+	(_DestBlock & 1) * COLOUR_TILE_WIDTH
				+	(_DestBlock >> 1) * COLOUR_TILE_SIZE;

	for (y = 0; y < COLOUR_TILE_HEIGHT; y++)
	{
		DmaCopy(3,					// DMA 3
				ColourSource,		// The source colour tile from ROM
				ColourDest,			// My (are) specific little rendering block.
				COLOUR_TILE_WIDTH,	// 32 bytes.
				32);				// 32 bit bus (assuming that it is in CPURAM).

		// Next line.
		ColourSource	+= COLOUR_TILE_WIDTH << 1;		
		ColourDest		+= COLOUR_TILE_WIDTH << 1;
	}
}


// ----
// Update the map data for rendering.
void	Dakar_RefreshMap()
{
	// This code needs to be worked on to update the map.
	// As yet I don't know where the data is coming from, or who to process it.

	// Right, updating the map will for now be a bit dumb, 
	// not looking for diagonal updates.

	// ----
	// MOVING RIGHT
	if (Dakar_ViewPosition.X > 384)	// 384 >> 8 = 1.5
	{
		// Move the data in the two RH areas into the two LH areas.
		Dakar_MoveMapRegion(1, 0);
		Dakar_MoveMapRegion(3, 2);

		// Update the two RH areas - don't know how I'm 
		// supposed to determine the first parameter for 
		// this call!!!
		Dakar_CopyRomTileToRam(0, 1);
		Dakar_CopyRomTileToRam(0, 3);

		Dakar_ViewDirection.X -= 256;	// Shift camera to left too.
	}

	// ----
	// MOVING LEFT
	if (Dakar_ViewPosition.X < 128)	// 128 >> 8 = 0.5.
	{
		// Move the data in the two LH areas into the two RH areas.
		Dakar_MoveMapRegion(0, 1);
		Dakar_MoveMapRegion(2, 3);

		// Update the two LH areas - don't know how I'm 
		// supposed to determine the first parameter for 
		// this call!!!
		Dakar_CopyRomTileToRam(0, 0);
		Dakar_CopyRomTileToRam(0, 2);

		Dakar_ViewDirection.X += 256;	// Shift camera to right too.
	}

	// ----
	// MOVING UP
	if (Dakar_ViewPosition.Y < 128)	// 128 >> 8 = 0.5.
	{
		// Move the data in the two TM areas into the two BM areas.
		Dakar_MoveMapRegion(0, 2);
		Dakar_MoveMapRegion(1, 3);

		// Update the two TM areas - don't know how I'm 
		// supposed to determine the first parameter for 
		// this call!!!
		Dakar_CopyRomTileToRam(0, 0);
		Dakar_CopyRomTileToRam(0, 1);

		Dakar_ViewDirection.Y += 256;	// Shift camera upward too.
	}

	// ----
	// MOVING DOWN
	if (Dakar_ViewPosition.Y > 384)	// 384 >> 8 = 1.5
	{
		// Move the data in the two BM areas into the two TM areas.
		Dakar_MoveMapRegion(2, 0);
		Dakar_MoveMapRegion(3, 1);

		// Update the two BM areas - don't know how I'm 
		// supposed to determine the first parameter for 
		// this call!!!
		Dakar_CopyRomTileToRam(0, 2);
		Dakar_CopyRomTileToRam(0, 3);

		Dakar_ViewDirection.Y -= 256;	// Shift camera downward too.
	}
}

// ----
LONG	CamScale[80];
void	Dakar_SetCamera()
{
	INT i;

	// Set up camera scaling factors - this will eventually be a hardcoded lookup table.
	for (i = 1; i < 80; i++)
	{
		CamScale[i] = (8192 * 2) / (i);
	}

	//	Graphics_ActiveScreen = 1 - Graphics_ActiveScreen;
}

// ----
// Actually render the frame and flip the buffer.
#define LOWER 11
#define UPPER 40

UHWORD	tempCol;
UBYTE	*AddrStore;

void	Dakar_Render()
{
#if 0
	UBYTE		sx;			// X-screen pos (ray line)
	SHWORD		sy0;
	SHWORD		sy1;	// Y-screen variables.
	
	// All map co-ords are in 1.7.8 fixed point format
	SHWORD		mx, my;		// Map x and y (initilised as above, and modified by the following two variables per rayline step)
	SHWORD		mxd,myd;	// Map x, y deltas
	UBYTE		mxfp, myfp;	// Map fractional part.

	UBYTE		steps;		// Number of steps per rayline.

	SHWORD		cheight;	// Camera height
	SHWORD		py;			// Height of land at map point, (mx,my)
	UHWORD		tempCol, tempw, antTemp;

	UBYTE*		plocale;
	UBYTE*		Addr, *AddrStore;

	// Voxel technology.

	// The plain is simply to render the terrain as a voxel map.
	// Using a bitmap sky map. 
	// Correct rendering of surface objects.

	// Right. Could potentially use any screen mode.
	//	Bitmap modes will be too slow.
	//	Mode 0 or 1 seem suitable. 
	//	Mode 2 could allow for a limited z-axis rotation (zoom into smaller screen segment, and use hardware screen rotation).
	//	Mode 2, and mode 1 do not offer enough buffers.
	//	Thus mode 0

	// Mode 0.
	//	Four plain buffers

	// View cone, with single sweep (aptly illustraiting how poor integer maths can be).
	// \___________/
	//  \       . /
	//   \     . /
	//    \   . /
	//     \  ./
	//      \_/
	//		 v

	// No need to transform height map, as the x and y increments on the sweep are governed by the y-axis rotation.

	// ----
	// Test implementation

	//INTVECTOR			Dakar_ViewPosition;

	// Rest frame time counter (fps is actually the count of the number of v-blanks that occur during a frame render).
	fps = 0;

	// Clear the screen.
	Col.PaletteIndex = 255;
	Graphics_ClearScreen(Col);

	// Store screen base address.
	AddrStore = Graphics_Buffer[Graphics_ActiveScreen].Address;

	// Calculate interpolated camera height.
	//plocale = &Map_Alt[((Dakar_ViewPosition.Y >> 8) << 4) + (Dakar_ViewPosition.X >> 8)];
	/*
	
	plocale = &Map_Alt[(Dakar_ViewPosition.Y & 0x7F00) + (Dakar_ViewPosition.X >> 8)];
	cheight =	(	(	(*(UBYTE*)(plocale -1))		* (256 -	(Dakar_ViewPosition.X & 0xFF))
					+	(*(UBYTE*)(plocale +1))		* (			(Dakar_ViewPosition.X & 0xFF))
					+	(*(UBYTE*)(plocale -256))	* (256 -	(Dakar_ViewPosition.Y & 0xFF))
					+	(*(UBYTE*)(plocale +256))	* (		 	(Dakar_ViewPosition.Y & 0xFF))) >> 1) + 2560;
	*/
	
	mxfp = Dakar_ViewPosition.X & 0xFF;
	myfp = Dakar_ViewPosition.Y & 0xFF;

	plocale	= &Dakar_GraphicsMapHeight;
	plocale += ((my & 0x7F00) >> 2) + (mx >> 10);
	cheight =	(	(	(*(UBYTE*)(plocale -1))		* (256 -	mxfp)
					+	(*(UBYTE*)(plocale +1))		* (			mxfp)
					+	(*(UBYTE*)(plocale -64))	* (256 -	myfp)
					+	(*(UBYTE*)(plocale +64))	* (		 	myfp)) >> 1) + 2560;

	// Ray cast loop. (one per line of the horizontal display).
	for (sx = 0; sx < 80; sx ++)
	{
		// Recalculate bottom of screen address.
		Addr = AddrStore + 240 * sx;
	 
		// Set up offset values. 
		// These values are added to the mx, my values per rayline step.
		mxd = _Sin((Dakar_ViewDirection.Y + ((sx - 40) )) & 0xFF) >> 4;		// Calculate angle for ray line based on overall 
		myd = _Cos((Dakar_ViewDirection.Y + ((sx - 40) )) & 0xFF) >> 4;		// camera orientation and the ray line number.
		sy0 = 0;

		// Step coverns the distance scaling factor, and 
		// the number of sections that will be rendered.
		for (steps = LOWER; steps < UPPER; steps++)	// These values need to be set to give optamal fps and appearance.
		{
			// Step down the ray line. 
			mx += mxd;
			my += myd;

			// Cache info.
			mxfp = mx & 0xFF;
			myfp = my & 0xFF;

			// Get point height, minus observation piont.
	/*
			// This the prototype mape area.
			plocale = &Map_Alt[(my & 0x7F00) + (mx >> 8)];
			py =	(	(	(*(UBYTE*)(plocale -1))		* (256 -	mxfp)
						+	(*(UBYTE*)(plocale +1))		* (			mxfp)
						+	(*(UBYTE*)(plocale -256))	* (256 -	myfp)
						+	(*(UBYTE*)(plocale +256))	* (		 	myfp)) >> 1)
						-  cheight;
	*/
			//plocale	= &Dakar_Graphics_MapArea[((my & 0x7F00) >> 2) + (mx >> 10)];
			plocale	= &Dakar_GraphicsMapHeight;
			plocale += ((my & 0x7F00) >> 2) + (mx >> 10);
			py =	(	(	(*(UBYTE*)(plocale -1))		* (256 -	mxfp)
						+	(*(UBYTE*)(plocale +1))		* (			mxfp)
						+	(*(UBYTE*)(plocale -64))	* (256 -	myfp)
						+	(*(UBYTE*)(plocale +64))	* (		 	myfp)) >> 1)
						-  cheight;

				// Project into screen space.
			sy1 = FP16ToInt(FP16Mul(py, CamScale[steps])) + 53;	// Fixed point maths and a conversion back to a plain integer.

			/*
			Ys = ( Yv - Ye ) * Yk / Z + Yc

			Ys: coordinate projected onto the screen
			Yv: altitude of the voxel column
			Ye: coordinate of the eye
			Z: distance from the eye to the considered point
			Yk: constant to scale the projection, possibly negative
			Yc: constant to centre the projection, usually half the screen resolution
			*/

			// If pos is higher than previous so far...
			if (sy1 > sy0)
			{
#if 10	// are method - interpolated colour map + dithered depth shading.
				plocale	= &Dakar_GraphicsMapColour;
				plocale += ((my & 0x7F00) >> 3) + (mx >> 11);	// Only half the dimensions of the height map.
				Col.PaletteIndex =	(	(	(*(UBYTE*)(plocale -1))		* (256 -	mxfp)
										+	(*(UBYTE*)(plocale +1))		* (			mxfp)
										+	(*(UBYTE*)(plocale -32))	* (256 -	myfp)
										+	(*(UBYTE*)(plocale +32))	* (		 	myfp)) >> 1);

				// The following code is useful for creating
				// a dithered depth shading effect - but 
				// assumes the palette is linear. If the 
				// palette is not linear then we'll have to 
				// resort to something else.
				if (sx & 1)
					tempCol = (Col.PaletteIndex & 0xFF00) | (UPPER-steps);		// Faster
				else
					tempCol = ((UPPER-steps) << 8) | (Col.PaletteIndex >> 8);	// Slower

#else	// asd method - depth shading.
				// Two colours together.
				tempCol = ((UPPER-steps) << 8) | (UPPER-steps);
#endif
				
				// Run length...
				tempw = (sy1 - sy0);
				if (tempw & 1)	// 16bit writes.
					tempw++;

				// Dma to addr, and increment for next round.
				DmaClear(3, tempCol, Addr, tempw, 16);

				//Interpolate between heights on hills to give appearance of smoothness
				if(tempw > 5)
				{
					antTemp = tempw >> 1;

					if (antTemp & 1)	// 16bit writes.
						antTemp++;

					DmaClear(3, (tempCol + 1), (Addr - 2), antTemp, 16);

					if(tempw > 19)
					{
						antTemp = antTemp >> 1;

						if (antTemp & 1)	// 16bit writes.
						antTemp++;

						DmaClear(3, (tempCol + 2), (Addr - 4), antTemp, 16);

						if(tempw > 59)
						{
							antTemp = antTemp >> 1;

							if (antTemp & 1)	// 16bit writes.
							antTemp++;

							DmaClear(3, (tempCol + 1), (Addr - 6), antTemp, 16);

							if(tempw > 159)
							{
								antTemp = antTemp >> 1;

								if (antTemp & 1)	// 16bit writes.
								antTemp++;

								DmaClear(3, (tempCol + 2), (Addr - 8), antTemp, 16);
							}
						}
					}	
				}
				
				// Update highest.
				sy0 = sy1;
				Addr += tempw;

				// Break if highest is off top of screen.
				if (sy0 >= 107)
					break;
			}
		}

		// unfold loop above to work at different step rates.
		mxd <<= 1;
		myd <<= 1;

		// Draw in sky line.
		if (sy0 < 107)
		{
			Col.PaletteIndex = 255;
			Graphics_DrawHorizontal(sy0, 107, sx, &Col);
		}
	}
	

	// fps is now the numebr of v-blanks that it took to render the frame.
	Col.PaletteIndex = 1;
	for (sx = 0; sx < 100; sx += 5)
	{
		Graphics_DrawHorizontal(90, 100, sx, &Col);
	}
	if (fps > 0)
	{
		for (sx = 0; sx < (60 / fps); sx++)
		{
			Graphics_DrawHorizontal(92, 98, sx, &Col);
		}
	}
	
	if (method)
	{
		for (sx = 150; sx < 160; sx++)
		{
			Graphics_DrawHorizontal(92, 98, sx, &Col);
		}
	}

	// Swap buffers.
	Dakar_GameDrawCar();
	Graphics_SwapScreens();

#else
	// Include some assembly code.

	
#if 1
asm ("

	push {r3}

	@ Enter ARM Mode
	adr    r3,2f		@ Get address of label 2 (f means the label is below[f=forward] instead of above[b=backward])
	bx	   r3

	.ALIGN				@ This is required before all ARM code, or you can use .CODE 32 here
	.ARM
2:

	@ All comments will use this format, making it easier to
	@ search and replace them should I need to.

	.EXTERN 	AddrStore
	.EXTERN 	Dakar_GraphicsMapHeight
	.EXTERN 	Dakar_ViewPosition
	.EXTERN 	Graphics_ActiveScreen
	.EXTERN 	sin_cos_table
	.EXTERN 	tempCol

Dakar_Render_asm:

	stmfd   sp!,{r0-r12}

	@ Calculate screen base address.
	@ If Graphics_ActiveScreen == 0 
	@		r1 = #0x06000000
	@ else
	@		r1 = #0x0600a000
	LDr		r1, =Graphics_ActiveScreen
	LDr		r0, [r1]
	MOV		r1,	#0x06000000				
	CMP		r0, #0
	BEQ		Dr_AddStore
	ADD		r1, r1, #0x0a000

Dr_AddStore:
	@ Now need to store value out.
	LDr		r0, =AddrStore
	STRH	r0, [r1]

	@ All registers are be safe to use.

	@ Now calculate mxfp and myfp.
	LDr		r0,	=Dakar_ViewPosition
	LDr		r8, [r0]		@ mx
	AND		r10, r8, #0xFF	@ mxfp

	ADD		r0, r0, #2
	LDr		r9, [r0]		@ my
	AND		r11, r9, #0xFF	@ myfp

	@ 8, 9, 10, 11 in use

	@ Calculate plocale	
	LDr		r0, =Dakar_GraphicsMapHeight
	
	@ Add ((my & 0x7F00) >> 2)
	AND		r1, r9, #0x7F00
	MOV		r1, r1, LSR #2
	ADD		r0, r0, r1

	@ Add (mx >> 10)
	MOV		r1, r8, LSR #10
	ADD		r0, r0, r1

	@ r0 should now contain plocale's value.

	SUB		r0, r0, #1
	LDrB	r1, [r0]
	rSB		r2, r10, #256
	MUL		r12, r1, r2

	ADD		r0, r0, #2
	LDrB	r1, [r0]
	MLA		r12, r1, r10, r12

	SUB		r0, r0, #66
	LDrB	r1, [r0]
	rSB		r2, r11, #256
	MLA		r12, r1, r2, r12

	ADD		r0, r0, #128
	LDrB	r1, [r0]
	MLA		r12, r1, r11, r12

	MOV		r12, r12, LSR #1
	ADD		r12, r12, #2560

	@ Now for the main loop.
	MOV		r4, #0				@ sx
Dr_LineCastLoop:

		@ Addr = AddrStore + 240 * sx;
		LDr		r0, =AddrStore
		LDr		r1, [r0]
		MOV		r7, #240
		MLA		r7, r4, r7, r1

		@ Calculate mxd and myd
		LDr		r0, =Dakar_ViewDirection
		ADD		r0, r0, #2
		LDr		r1, [r0]
		ADD		r1, r1, r4
		SUB		r1, r1, #40
		AND		r1, r1, #0xFF
		MOV		r1, r1, LSL#1	@ Multiply by 2 so to take data size into account.

		LDr		r0, =sin_cos_table
		ADD		r0, r0, r1
		LDr		r10, [r0]
		MOV		r10, r10, LSR #4

		ADD		r0, r0, #64
		LDr		r11, [r0]
		MOV		r11, r11, LSR #4

		@ sy0 = 0
		MOV		r6, #0


		@ Now for the inner loop.
		MOV		r5, #11				@ steps = LOWEr (11)
Dr_LineStepLoop:

			ADD		r8, r8, r10
			ADD		r9, r9, r11

			@ Calculate plocale	
			LDr		r0, =Dakar_GraphicsMapHeight
			
			@ Add ((my & 0x7F00) >> 2)
			AND		r1, r9, #0x7F00
			MOV		r1, r1, LSR #2
			ADD		r0, r0, r1

			@ Add (mx >> 10)
			MOV		r1, r8, LSR #10
			ADD		r0, r0, r1
						
			@ Calculate point height, minus observation point. (py)
			SUB		r0, r0, #1
			LDrB	r1, [r0]
			AND		r2, r8, #0xFF	@ mx & 0xFF
			rSB		r2, r2, #256
			MUL		r3, r1, r2

			ADD		r0, r0, #2
			LDrB	r1, [r0]
			AND		r2, r8, #0xFF	@ mx & 0xFF
			MLA		r3, r1, r2, r3

			SUB		r0, r0, #66
			LDrB	r1, [r0]
			AND		r2, r9, #0xFF	@ my & 0xFF
			rSB		r2, r2, #256
			MLA		r3, r1, r2, r3

			ADD		r0, r0, #128
			LDrB	r1, [r0]
			AND		r2, r9, #0xFF	@ my & 0xFF
			MLA		r3, r1, r2, r3

			MOV		r3, r3, LSR #1
			SUB		r3, r3, r12
		
			
			@ Project into screen space.
			LDr		r0, =CamScale
			MOV		r1, r5, LSL #1
			ADD		r0, r0, r1
			LDr		r2, [r0]		@ CamScale value.

			@ Fix point mul of r2 and r3
			MUL		r0, r2, r3
			MOV		r0, r0, LSR #16	@ FP16 mul and FP16ToInt in one op.
			ADD		r0, r0, #53		@ 53 is half way up the display (horizon point).
			
			@ if sy1 <= sy0 then continue - i.e. don't render.
			CMP		r0, r6
			BLE		Dr_LineStepLoopEnd

			@ Calculate colour.
			rSB		r1, r5, #40		@ (UPPEr - steps)
			MOV		r2, r1, LSL #8
			Orr		r2, r1, r2
			
			@ Need to store this information out to rAM, 
			@ so that the co-pro can access it.
			LDr		r1, =tempCol
			STrH	r2, [r1]

			@ render time
			SUB		r3, r0, r6
			TST		r3, #1
			BNE		Dr_EvenLength
			
			@ Bit 1 was set, thus the number was odd, 
			@ therefore we'll add one to its length so 
			@ we have a 16bit write.
			ADD		r3, r3, #1
Dr_EvenLength:
			
			@	r0	DMA line
			@	r1	Address of Data
			@	r2	Destination
			@	r3	Length >> 1 | stuff

	@		MOV		r0, #3				@ DMA line
	@	@	LDr		r1, =tempCol		@ Address of tempCol (already held)
			MOV		r2, r7				@ Dest Addr			
			MOV		r3, r3, LSR #1
			@AND		r3, r3, #0xFFFF
			MOV		r3, r3, LSL#16
			MOV		r3, r3, LSR#16
			Orr		r3, r3, #0x81000000	@ Values from the expansion of DmaClear macro 	

	@		BL		DmaSet				@ Call DmaSet code.

			MOV		r0, #0x04000000
			ADD		r0, r0, #0xd4
			STR		r1, [r0]
			
			ADD		r0, r0, #4
			STR		r2, [r0]

			ADD		r0, r0, #4
			STR		r3, [r0]

			@ Update highest.
			MOV		r6, r1
			
			@ reverse calculate length and increment Addr
			@AND		r3, r3, #0xFFFF
			MOV		r3, r3, LSL#16
			MOV		r3, r3, LSR#16
			MOV		r3, r3, LSL #1
			ADD		r7, r7, r3

			@ Quit exit inner loop if we are off the top of the screen.
			CMP		r6, #107
			BGE		Dr_LineCastLoopEnd

		@ End of steps loop.
Dr_LineStepLoopEnd:
		ADD		r5, r5, #1
		CMP		r5, #40		@ UPPEr
		BL		Dr_LineStepLoop

		@ Update sky here - maybe.

	

	@ End of sx loop.
Dr_LineCastLoopEnd:
	ADD		r4, r4, #1
	CMP		r4, #80
	BL		Dr_LineCastLoop

	@ Drop out of outer loop.

	@ Call other draw routines.
	BL	Dakar_GameDrawCar
	BL	Graphics_SwapScreens

	ldmfd   sp!,{r4-r5}

	@ Enter Thumb mode
      adr    r3,3f + 1
      bx     r3

      .THUMB                   @ ..or you can use .CODE 16 here
	  pop {r3}
3:
      " :
      /* No output */ :               // No output is returned from this routine
      /* No input */:                 // Define the routine inputs (%0,%1,%2) even if we don't use them
      "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "r12");             // Specific which registers we destroy

#endif
#endif
}

/*
#define FOCAL_DISTANCE 200
void Project(VPOINT	*_Vertex)
{
	if(!_Vertex->z)
		_Vertex->z=1;

	_Screen.x = fpMul(_Vertex->x, FOCAL_DISTANCE);
	_Screen.y = fpMul(_Vertex->y, FOCAL_DISTANCE);
	_Screen.x = fpDiv(_Screen.x, _Vertex->z);
	_Screen.y = fpDiv(_Screen.y, _Vertex->z);
	_Screen.x	+= 120 << 14
	_Screen.y	+= 80 << 14;
}
*/

// ----
// Setup the rendering process, which will be 
// controlled by the two functions above.

#define	FOCAL_DISTANCE	200
#define	DAKAR_HORIZON_SIZE		
void	Dakar_SetUpRender()
{
	int		i, y;
	UBYTE*	Source;

	// Can't remember what this was...
	DmaArrayCopy(3, TrackPalette,	BG_PLTT,		32);
	for(i = 0; i < 256; i++)
	{
		TrackPalette[i] = i << PLTT_RED_SHIFT;
	}
	DmaArrayCopy(3, TrackPalette,	OBJ_PLTT,		32);

	
}

// ----
// Adds a polygon to the rendering list.
// Use inline code, it is too slow to make function calls.
void	Dakar_AddTriangle(INT _X0, INT _Y0,
						  INT _X1, INT _Y1,
						  INT _X2, INT _Y2,
						  COLOUR	_Col)
{
	/*
	INT	i;
	i = 3 * PolyCount;

	if (PolyCount < MAX_NUMBER_OF_POLYS)
	{
		PolyPointArray[i + 0].X		= _X0;
		PolyPointArray[i + 0].Y		= _Y0;
		PolyPointArray[i + 1].X		= _X1;
		PolyPointArray[i + 1].Y		= _Y1;
		PolyPointArray[i + 2].X		= _X2;
		PolyPointArray[i + 2].Y		= _Y2;
		PolyColourArray[PolyCount]	= _Col;

		PolyCount++;
	}
	*/
}


// ----
// A string drawing routing specific to the game. 
void	Dakar_GameDrawString(INT	_X,
							 INT	_Y, 
							 CHAR*	_String,
							 UBYTE	_Style)
{
	CHAR*	Index;
	CHAR	Char;
	SBYTE	Offset;
	Index = _String;

	Offset = 0;
	if (_Style & TEXT_RIGHT)
		Offset = -strlen(_String);

	if (_Style & TEXT_CENTRED)
		Offset = -(strlen(_String) >> 1);

	while (*Index)
	{
		Char = *Index;
		if ((Char < 65) && (Char >= (65 + 26)))
		{
			Char = 0;	// Clear unknown chars
		}
		*(UHWORD*)(Graphics_Buffer[1].Address + 2 * (32 * _Y + _X + Offset)) = Char - 'A' + 1;
		
		Index++;
		_X++;
	}
}

/*
	OK not to sure if this is going to work "and" be fast enough but maybe I can be clever....
	The way this should work is I have a car built from voxels in a 3d grid,
	Each entry in the grid is a colour value for that cube.
	Then when I need to show the car what I do is this.
	Set up a scan linefrom the direction I want at a set distance.
	move through the array and scan all the pixels that the scanline meets into 
	the top part of object ram. This can then be drawn very quickly onto the screen
	by the harware.
	The most difficult part of this will be setting up the scanlines properly....
*/
//need some globals here... sorry

//This is basically the picture which my scanline camera will take.
//It is stored temporarily in this array then DMA's straight into object ram....
UBYTE	Canvas[32 * 32];

#define XSHIFT	6
#define	ZSHIFT	12

void	Dakar_GameDrawCar()
{
	//I think that, just to begin with, I'll set the camera at the back of the car...
	UBYTE * pointer; 
	UBYTE * temp; //Pointer into the car data
	UBYTE * zposp;
	VECTOR	CamPos, RayTarget; //the start and end pooints for our camera rays
	int		CanvasPos; //Canvas pos is incremented once we put a colour on it

	unsigned long ObjAtt1, ObjAtt2, ObjAtt3; //Temporary until I write an object manager

	int                 i, dx, dy, dz, l, m, n, x_inc, y_inc, z_inc, 
						err_1, err_2, dx2, dy2, dz2, dist, z, x;


	CamPos.x = 32;	
	CamPos.y = 0;	
	CamPos.z = 32;	

	RayTarget.x = 32;
	RayTarget.y = 64;
	RayTarget.z = 32;

	CanvasPos = 0;

	dx = CamPos.x - RayTarget.x;	//differences between the values
	dy = CamPos.y - RayTarget.y;
	dz = CamPos.z - RayTarget.z;

	z_inc = (dz < 0) ? -1 : 1;		//These are the increments for the pointer..
	x_inc = (dx < 0) ? -64 : 64;
	y_inc = (dy < 0) ? -4096: 4096;
	
	l = dx & /*-dx;//*/0x7FFFFFFF; //take the absolute value of these variables
	m = dy & /*-dy;//*/0x7FFFFFFF;
	n = dz & /*-dz;//*/0x7FFFFFFF;

	dx2 = l << 1;
    dy2 = m << 1;
    dz2 = n << 1;
	
	temp	= CarData;

	for(z = 16; z < 48; z++)
	{
		zposp = temp + (z);

		for(x = 16; x < 48; x++)
		{
			dist = 0;
			pointer = zposp + (x << 6);

			if ((l >= m) && (l >= n)) 
			{
				err_1 = dy2 - l;
				err_2 = dz2 - l;
				for (i = 0; i < l; i++) 
				{
					if(*(pointer))
					{
						goto end;
					}
					if (err_1 > 0) 
					{
						pointer += y_inc;
						err_1 -= dx2;
					}
					if (err_2 > 0) 
					{
						pointer += z_inc;
						err_2 -= dx2;
					}
					err_1 += dy2;
					err_2 += dz2;
					pointer += x_inc;
					dist++;
				}
			} 
			else if ((m >= l) && (m >= n)) 
			{
				err_1 = dx2 - m;
				err_2 = dz2 - m;
				for (i = 0; i < m; i++) 
				{
					if(*(pointer))
					{
						goto end;
					}
					
					if (err_1 > 0) 
					{
						pointer += x_inc;
						err_1 -= dy2;
					}
					if (err_2 > 0) 
					{
						pointer += z_inc;
						err_2 -= dy2;
					}
					
					err_1 += dx2;
					err_2 += dz2;
					pointer += y_inc;
					dist++;
				}
			} 
			else 
			{
				err_1 = dy2 - n;
				err_2 = dx2 - n;
				for (i = 0; i < n; i++) 
				{
					if(  *(pointer) )
					{
						goto end;
					}
					if (err_1 > 0) 
					{
						pointer += y_inc;
						err_1 -= dz2;
					}
					if (err_2 > 0) 
					{
						pointer += x_inc;
						err_2 -= dz2;
					}
					err_1 += dy2;
					err_2 += dx2;
					pointer += z_inc;
					dist++;
				}
			}

		end:
			Canvas[CanvasPos] = *(pointer) + dist;//*pointer; //+ (dist << 2));
			CanvasPos++;
		}
	}

	ObjAtt1 = 120 | OAM_AFFINE_NORMAL | OAM_OBJ_NORMAL | OAM_MOS_OFF | OAM_COLOR_256 | OAM_SQUARE;
	ObjAtt2 = 100 | OAM_SIZE_NO_2;
	ObjAtt3 = 512 | (00 << OAM_PRIORITY_SHIFT);
	*(UHWORD*)OAM = ObjAtt1;
	*(UHWORD*)(OAM+2) = ObjAtt2;
	*(UHWORD*)(OAM+4) = ObjAtt3;
	DmaArrayCopy(  3, Canvas, OBJ_MODE4_VRAM, 16);
	
}

