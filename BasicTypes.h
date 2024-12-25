// FILE:		BasicTypes.h
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// ----
// COMMENT:		Define all types here.

#ifndef _BASICTYPES_H_
#define _BASICTYPES_H_

// ----
// Very basic types.
typedef	signed char				BOOL;
								
typedef	unsigned char			UBYTE;
typedef	unsigned short			UHWORD;	
typedef	unsigned long			UWORD;
								
typedef	signed char				SBYTE;
typedef	signed short			SHWORD;	
typedef	signed long				SWORD;
								
typedef	unsigned char			UCHAR;
typedef	unsigned short			USHORT;
typedef	unsigned long			ULONG;
								
typedef	signed char				SCHAR;
typedef	signed short			SSHORT;
typedef	signed long				SLONG;
								
typedef	signed char				CHAR;
typedef	signed short			SHORT;
typedef	signed long				LONG;
								
typedef	char					TCHAR;
typedef	signed short			INT;
typedef double					DOUBLE;

typedef	volatile unsigned char	VUBYTE;
typedef	volatile unsigned short	VUHWORD;	
typedef	volatile unsigned long	VUWORD;

typedef	volatile signed char	VSBYTE;
typedef	volatile signed short	VSHWORD;	
typedef	volatile signed long	VSWORD;


// ----
// A structure for store the co-ordinates of a point.
typedef 
struct	_INTCOUPLE
{
	SSHORT	X;
	SSHORT	Y;
}
INTCOUPLE, 
POINT;

// ----
// A structure for storing the co-ordinates of a rectangle.
typedef 
struct	_INTQUAD
{
	SSHORT	y0;
	SSHORT	x0;
	SSHORT	y1;
	SSHORT	x1;
}
INTQUAD,
RECT,
HGVECTOR;

// ----
typedef
struct	_INTTRIPLE
{
	SSHORT	X;
	SSHORT	Y;
	SSHORT	Z;
}
INTTRIPLE,
INTVECTOR;	// Unfortunately the name VECTOR has already been used.

// ----
// For storing RGB components
#if 0	// Not required for this project
struct	_RGB
{
	UBYTE	R, G, B;
};
#endif

// ----
// For storing colour information.
typedef
union	_COLOUR
{
//	_RGB	RGBSeperates;
	UBYTE	PaletteIndex;
	UHWORD	RGBDirect;
}
COLOUR;


struct MapStruct
{
	UBYTE	Alt;
	UBYTE	Col;
};

//typedef	_COLOUR			COLOUR;

#endif