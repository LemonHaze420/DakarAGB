// FILE:		Controls.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:

// INCLUDES:
#include	"Controls.h"
#include	"BasicDefines.h"
#include	"Debug.h"

// ----
// Initialise the controls system.
void	Controls_Init()
{
	Controls_CurrentButtonState	= 0;
	Controls_PreviousButtonState	= 0;
}

// ----
// Process controls.
void	Controls_Process()
{
	Controls_PreviousButtonState = Controls_CurrentButtonState;
	Controls_CurrentButtonState	= (*(VUHWORD*)REG_KEYINPUT) ^ 0xFFFF;

	// Reset buffer - as the device doesn't do it itself - apparently.
	*(VUHWORD*)REG_KEYINPUT = 0xFFFF;
}

// ----
// Get current button state and a debounced version.
BOOL	Controls_IsButtonPressed(enum EButton _Button)
{
	return ((Controls_CurrentButtonState & (1 << (UBYTE)_Button)) > 0);
}

// ----
BOOL	Controls_IsButtonPressedDB(enum EButton _Button)
{
	UBYTE index = (UBYTE)_Button;
	return	(	(Controls_CurrentButtonState & (1 << index))
			&&	(!(Controls_PreviousButtonState & (1 << index)))
			);
}
