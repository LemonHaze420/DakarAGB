// FILE:		Controls.h
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:

// INCLUDES:
#include	"BasicTypes.h"
#include	"Macros.h"
#include	"AgbMemoryMap.h"

#ifndef	_CONTROLS_H_
#define _CONTROLS_H_

// ----
// The in game buttons.
// Note, the value are important
enum EButton
{
	FireA			= 0,
	FireB			= 1,

	Select			= 2,
	Start			= 3,

	Right			= 4, 
	Left			= 5,
	Up				= 6,
	Down			= 7,

	RightShoulder	= 8,
	LeftShoulder	= 9
};

// ----
// Initialise the controls system.
void	Controls_Init();

// ----
// Process controls.
void	Controls_Process();

// ----
// Get current button state and a debounced version.
BOOL	Controls_IsButtonPressed(enum EButton _Button);
BOOL	Controls_IsButtonPressedDB(enum EButton _Button);

// Variables that should be protected.
UHWORD	Controls_CurrentButtonState;
UHWORD	Controls_PreviousButtonState;

#endif