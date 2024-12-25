// FILE:		Debug.h
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// INCLUDES:
#include	"BasicTypes.h"

// ----
// Global buffer for debug operations.
CHAR	Debug_Buffer[256];

// ----
// Show a red error bar - in an attempt to debug the program.
void	Debug_ErrorBar(INT _Number);

// ----
// show a bar across the screen - in an attempt to indicate program flow.
void	Debug_HereIambar(INT _Number);

// ----
// Call this inplace of an __assume statement - such as in 
// an 'undefined' switch statement.
void	Debug_NoSuchChoice(CHAR*	_File, LONG	_Line, CHAR*	_Msg);
