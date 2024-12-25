// FILE:		AdditionalAGBDefines.h
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// ----
// COMMENT:		Define values about the AGB platform that
//				aren't defined by Nintendo header files.

#ifndef _ADDITIONALAGBDEFINES_H_
#define	_ADDITIONALAGBDEFINES_H_

// Defining the size of backgrounds for the particular modes.
#define	BG_TEXT_SIZE0_WIDTH			32
#define	BG_TEXT_SIZE0_HEIGHT		32
#define	BG_TEXT_SIZE0_MEM_SIZE		2048	// 32 * 32 * 2
#define	BG_TEXT_SIZE1_WIDTH			64
#define	BG_TEXT_SIZE1_HEIGHT		32
#define	BG_TEXT_SIZE1_MEM_SIZE		4096
#define	BG_TEXT_SIZE2_WIDTH			32
#define	BG_TEXT_SIZE2_HEIGHT		64
#define	BG_TEXT_SIZE2_MEM_SIZE		4096
#define	BG_TEXT_SIZE3_WIDTH			64
#define	BG_TEXT_SIZE3_HEIGHT		64
#define	BG_TEXT_SIZE3_MEM_SIZE		8192

#define	BG_ROTATION_SIZE0_WIDTH		16
#define	BG_ROTATION_SIZE0_HEIGHT	16
#define	BG_ROTATION_SIZE0_MEM_SIZE	256		// 16 * 16 * 1
#define	BG_ROTATION_SIZE1_WIDTH		32
#define	BG_ROTATION_SIZE1_HEIGHT	32
#define	BG_ROTATION_SIZE1_MEM_SIZE	1024
#define	BG_ROTATION_SIZE2_WIDTH		64
#define	BG_ROTATION_SIZE2_HEIGHT	64
#define	BG_ROTATION_SIZE2_MEM_SIZE	2048
#define	BG_ROTATION_SIZE3_WIDTH		128
#define	BG_ROTATION_SIZE3_HEIGHT	128
#define	BG_ROTATION_SIZE3_MEM_SIZE	16384

#define	MODE3_WIDTH					240
#define	MODE3_HEIGHT				160
#define	MODE3_MEM_SIZE				76800	// 240 * 160 * 2

#define	MODE4_WIDTH					240
#define	MODE4_HEIGHT				160
#define	MODE4_MEM_SIZE				38400	// 240 * 160 * 1

#define	MODE5_WIDTH					160
#define	MODE5_HEIGHT				128
#define	MODE5_MEM_SIZE				40960	// 160 * 128 * 2

// Defining the step size between possible memory addresses for storing graphics data.
#define	BG_MODE0_VRAM_STEP_SIZE		2048	// 2K between addrs for potential storage areas.
#define	BG_MODE1_VRAM_STEP_SIZE		2048	// 2K between addrs for potential storage areas.
#define	BG_MODE2_VRAM_STEP_SIZE		2048	// 2K between addrs for potential storage areas.
#define	BG_MODE3_VRAM_STEP_SIZE		0		// There is no second buffer.
#define	BG_MODE4_VRAM_STEP_SIZE		40960	// 40K for each buffer.
#define	BG_MODE5_VRAM_STEP_SIZE		40960	// 40K for each buffer.

#define	BG_TEXT_MODES_VRAM_STEP_SIZE	2048
#define	BG_BITMAP_MODES_VRAM_STEP_SIZE	40960

#endif