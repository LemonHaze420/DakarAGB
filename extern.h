// FILE:		Extern.h
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:

#ifndef	_EXTERN_H_
#define	_EXTERN_H_

#include	<AGBTypes.h>
#include	"BasicTypes.h"
#include	"Vector.h"

extern			CHAR	Buffer[256];	// A global buffer
extern			COLOUR	Col;			// A colour struct.

// Registers.
extern const	UHWORD	*BGCntRegs[4];		// An array of register indecies
extern const	UHWORD	*BGXOffsetRegs[4];	// BG x-offset registers
extern const	UHWORD	*BGYOffsetRegs[4];	// BG y-offset registers
extern const	UHWORD	*BGXLRegs[4];		// BG rotation / scaling registers
extern const	UHWORD	*BGYLRegs[4];
extern const	UHWORD	*BGXHRegs[4];
extern const	UHWORD	*BGYHRegs[4];
extern const	UHWORD	*BGPARegs[4];
extern const	UHWORD	*BGPBRegs[4];
extern const	UHWORD	*BGPCRegs[4];
extern const	UHWORD	*BGPDRegs[4];


// Graphics
extern const	u8		Alphaset1_Char[64*208/8*8/8 + 0];
extern const	u16		Alphaset1_Palette[256];

extern const	u8		MainMenu_Character[8*8*248];
extern const	u8		MainMenu_Map[30*20];
extern const	u16		MainMenu_Palette[256];

extern const	u8		Track_Character[8*8*223];
extern const	u8		Track_Map[16*16];

//extern	struct MapStruct	Map[256][256];
//extern const	u8 Map_Alt[256*256];
//extern const	u8 Map_Alt[16*16];
extern const	u8 Map_Alt[256*256];

extern			u16		TrackPalette[256];

extern const unsigned char HeightTileArray[];
extern const unsigned char ColourTileArray[];
extern const unsigned char TestIndexArray[];

extern unsigned char Viewport[1024];

extern const unsigned char CarData[64][64][64];	//A 3d array which is about twice the size of the car 
											//that will be inside it

extern	const u16 MainBackground_Palette[256];
extern	const u8 MainBackground_Char[64*240/8*160/8 + 0];

#endif