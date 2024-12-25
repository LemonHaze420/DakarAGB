// FILE:		Platform.h
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:

// COMMENTS:	This family of function is designed to act as abstraction 
//				layer, sperating the program from the device platform. The 
//				idea being that this should aid the task of porting the 
//				code to other platforms. (Known as forward planning :o)
//				Some prototype may have to change between platforms, however.

// INCLUDES:
#include	"Agb.h"
#include	"BasicTypes.h"
#include	"BasicDefines.h"

#ifndef	_PLATFORM_H_
#define	_PLATFORM_H_

// ----
// Initialise the platform so that it is ready to use.
// Returns true to indicate success, and FALSE to indicate failure
BOOL	Platform_Init();

// ----
// This function will try and tell the user there is a 
// problem with the platform.
void	Platform_Error();

// ----
// Clear all RAM on the device.
void	Platform_ClearAllMemory();

// ----
// Clear individual areas of RAM.
void	Platform_ClearCPURAM();
void	Platform_ClearWRAM();
void	Platform_ClearVRAM();
void	Platform_ClearOAM();
void	Platform_ClearPalette();

#endif