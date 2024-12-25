// FILE:		Graphics.h
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:

// INCLUDES:
#include	"BasicTypes.h"
#include	"Macros.h"
#include	"AgbMemoryMap.h"

#ifndef	_GRAPHICS_H_
#define _GRAPHICS_H_

// Max possible screen buffers
#define	GRAPHICS_MAX_BUFFERS				4
											
#define	GRAPHICS_DISPLAY_FRAME_BUFFER_BIT	4

#define	GRAPHICS_DISPLAY_BG0_BIT			8
#define	GRAPHICS_DISPLAY_BG1_BIT			9
#define	GRAPHICS_DISPLAY_BG2_BIT			10
#define	GRAPHICS_DISPLAY_BG3_BIT			11
#define	GRAPHICS_DISPLAY_OAM_BIT			12

// Masks for text mode.
#define	BG_STYLE_PURE_TEXT					(1 << 0)
#define	BG_STYLE_ROTATION_TEXT				(1 << 1)
#define	BG_STYLE_TEXT						(BG_STYLE_PURE_TEXT | BG_STYLE_ROTATION_TEXT)
#define	BG_STYLE_MODE3						(1 << 2)
#define	BG_STYLE_MODE4						(1 << 3)
#define	BG_STYLE_MODE5						(1 << 4)
#define	BG_STYLE_BITMAP						(BG_STYLE_MODE3 | BG_STYLE_MODE4 | BG_STYLE_MODE5)

#define	MAX_NUMBER_OF_TRIS					500	// 500 * (2 + 2 + 2 + 1) bytes (3500b)
// ----
// A record of the BGs / bitmaps attributes.
typedef
struct	_Graphics_BufferAttributesStruct
{
	UBYTE	*Address;	// Address of screen memory. Can be NULL if the BG is not accessable in this mode. 
	BOOL	Accessable;	// TRUE if the BG can be addressed in this mode.
	UBYTE	Width;		// Width of BG in characters in text modes, or actual pixel count in bitmap mode.
	UBYTE	Height;		// Height of BG in characters in text modes, or actual pixel count in bitmap mode.
	UHWORD	MemSize;	// Number of bytes (8bits) used to store the data.
	UBYTE	Style;		// A bit mask containing info about the background.

	UBYTE	CharBase;	// Character base location.
}
Graphics_BufferAttributesStruct;

typedef	void (*Graphics_DrawTriFunction)(POINT*, COLOUR*);

// ----
// Initialise the graphics system.
void	Graphics_Init(UBYTE	_Mode);

// ----
// Change to using a specific graphics mode.
void	Graphics_SetGraphicsMode(UBYTE	_Mode);

// ----
// Enable or disable a BG. 
// Not all BGs are available in all modes
// 0 - off.
// 1 - on.
void	Graphics_SetBackground(INT	_BackgroundIndex, INT _State);

// ----
// Set Background Priority
void	Graphics_SetBackgroundPriority(INT	_BackgroundIndex, INT	_Priority);

// ----
// Set Background Character	Base Block - no, I'm not sure what this is yet.
void	Graphics_SetBackgroundCharBaseBlock(INT	_BackgroundIndex, INT	_Base);

// ----
// Set Background Mosiac.
// 0 - off
// 1 - on
void	Graphics_SetBackgroundMosiac(INT	_BackgroundIndex, INT	_Mosiac);

// ----
// Set Background Colour Mode.
// 0 - for 16*16 colour palettes.
// 1 - for 1*256 colour palette.
void	Graphics_SetBackgroundColourMode(INT	_BackgroundIndex, INT	_ColourMode);

// ----
// Set Background Screen Base Block.
// Values between 0-31.
void	Graphics_SetBackgroundScreenBaseBlock(INT	_BackgroundIndex, INT	_BaseBlock);

// ----
// Set Background Transparency / wrap.
// This function only effects BG2 and 3.
// 0 - transparent display.
// 1 - wraparound display.
void	Graphics_SetBackgroundTransparency(INT	_BackgroundIndex, INT	_Effect);

// ----
// Set Background Screen Size.
// Values 0 - 3. 
void	Graphics_SetBackgroundScreenSize(INT	_BackgroundIndex, INT	_Size);

// ----
// Offset a background.
// Note, values must be positive!!!
void	Graphics_OffsetBackground(INT	_BackgroundIndex,
								  INT	_X, 
								  INT	_Y);

// ----
// Rotate / scale a background.
// Note, this function can on;y be applied to certain BGs in certain screen modes.
void	Graphics_RotateScaleBackground(	INT	_BackgroundIndex,
										INT	_XScale, 
										INT	_YScale,
										INT	_Rotation);

// Not available if we're not planning to use some bitmap modes.
//#if	defined GRAPHICS_SUPPORT_MODE_3 || defined GRAPHICS_SUPPORT_MODE_4 || defined GRAPHICS_SUPPORT_MODE_5

// ----
// Swap surfaces.
void	Graphics_SwapScreens();

// ----
// Draw a single pixel.
void	Graphics_DrawPixelXY(INT _X, INT _Y, COLOUR _Col);

// ----
// Draw a line.
void	Graphics_DrawLineXYXY(	INT _X0, INT _Y0, 
								INT _X1, INT _Y1, 
								COLOUR _Col);

// ----
// Draw internally referenced triangle array.
void	Graphics_DrawTriangleArray();

// ----
// Draw a single filled triangle.
void	Graphics_DrawFilledTriangle(POINT*	_TriPointArray,
									COLOUR*	_Col);

// ----
// Draw a horizontal line of pixels.
void	Graphics_DrawHorizontal(INT _X0, INT _X1, INT _Y, COLOUR *_Col);

// ----
// Clear the screen.
void	Graphics_ClearScreen(COLOUR	_Col);

//#endif

// ----
// Find the closest match to a colour from the currently loaded palette.
UBYTE	Graphics_GetIndexFromPalette(UBYTE _R, UBYTE _G, UBYTE _B);

// ----
// Modify a palette entry.
void	Graphics_SetPaletteColour(UBYTE	_Index, UBYTE _R, UBYTE _G, UBYTE _B);

// ----
// Find out what colour we are looking at. 
// The usefulness of this function is questionable - thus 
// remove if the function isn't used.
void	Graphics_GetPaletteColour(UBYTE	_Index, UBYTE *_R, UBYTE *_G, UBYTE *_B);


// ----
// What should be "protected" variables.
UBYTE							Graphics_DisplayMode;
UBYTE							Graphics_ActiveScreen;
//UBYTE							*Graphics_WorkingBuffer;
Graphics_BufferAttributesStruct	Graphics_Buffer[GRAPHICS_MAX_BUFFERS];

// ----
// Arrays for storing triangle data.
POINT							Graphics_TriPointArray[3 * MAX_NUMBER_OF_TRIS];
COLOUR							Graphics_TriColourArray[MAX_NUMBER_OF_TRIS];
UBYTE							Graphics_TriCount;

// ----
// Store code in RAM.
UWORD							Graphics_DrawTriBuffer[2048];
Graphics_DrawTriFunction		Graphics_DrawTriCode;

// ----
// Frees a particular object.
void	Graphics_FreeObject(UHWORD _ID);

// ----
// Frees all objects
void	Graphics_FreeAllObjects();

// ----
// Allocate a Object resource - the return value is the ID
// for the object resource, use this to set/modify an
// object's attributes.
// A return value equal to or greater than 1024 indicates failure.
UHWORD	Graphics_AllocateObjectSpace();

// ----
// Simpliar to 'Graphics_AllocateObjectSpace', but allows all 
// properties to be set in on go.
// Returns a value >= 1024 in the case of an error.
UHWORD	Graphics_AddObject(UHWORD	_ObjAttr0, 
						   UHWORD	_ObjAttr1, 
						   UHWORD	_ObjAttr2);

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
									UBYTE	_RotScaleParam);

// ----
// Allow the setting of all the possible attributes for an object.
void	Graphics_SetObjectXY				(UHWORD _ID, UHWORD	_X, UBYTE _Y);
void	Graphics_SetObjectSetRotScaleState	(UHWORD _ID, BOOL	_RotScalingState);
void	Graphics_SetObjectSetDoubleSize		(UHWORD _ID, BOOL	_RotScalingDoubleSize);
void	Graphics_SetObjectMode				(UHWORD _ID, UBYTE	_Mode);					// See page 60 of AGB programming manual for info.
void	Graphics_SetObjectMosiac			(UHWORD _ID, BOOL	_Mosaic);				// 0 = off. 1 = on.
void	Graphics_SetObjectColourMode		(UHWORD _ID, BOOL	_ColourMode);			// 0 = 15 colour. 1 = 256 colour.
void	Graphics_SetObjectShape				(UHWORD _ID, UBYTE	_Shape);				// 0 = square. 1 = horizontal. 2 = vertical.
void	Graphics_SetObjectRotationScaling	(UHWORD _ID, UBYTE	_RotScale);				// See page 64 of AGB programming manual for info.
void	Graphics_SetObjectSize				(UHWORD _ID, UBYTE	_Size);					// See page 63 of AGB programming manual for info.
void	Graphics_SetObjectFlipHorizontally	(UHWORD _ID, BOOL	_State);
void	Graphics_SetObjectFlipVertically	(UHWORD _ID, BOOL	_State);
void	Graphics_SetObjectPalette			(UHWORD _ID, UBYTE	_Palette);
void	Graphics_SetObjectPriority			(UHWORD _ID, UHWORD	_Priority);
void	Graphics_SetObjectCharacterName		(UHWORD _ID, UHWORD	_CharacterName);

UHWORD	Graphics_NumberOfAllocatedObjects;

#endif