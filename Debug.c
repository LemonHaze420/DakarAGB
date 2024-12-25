// FILE:		Debug.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// INCLUDES:
#include	"Debug.h"
#include	"AgbSystemCall.h"
#include	"IsAgbPrint.h"
#include	"BasicTypes.h"
#include	"Graphics.h"

void	Debug_ErrorBar(INT _Number)
{
	COLOUR	Col;
	INT		i;

	Graphics_Init(4);
	Graphics_SetPaletteColour(0, 150, 150, 255);
	Col.PaletteIndex = 0;
	Graphics_ClearScreen(Col);
	Graphics_SetPaletteColour(1, 255, 0, 0);
	Col.PaletteIndex = 1;
	for (i = 0; i < 10; i++)
	{
		Graphics_DrawLineXYXY(0, _Number * 10 + i, 240, _Number * 10 + i, Col);
	}
	Graphics_SwapScreens();

	while(1);	// Stay here.
}

void	Debug_HereIambar(INT _Number)
{
	COLOUR	Col;
	INT		i;

//	Graphics_SetPaletteColour(0, 150, 150, 255);
	Col.PaletteIndex = 0;
	Graphics_ClearScreen(Col);
//	Graphics_SetPaletteColour(1, 255, 0, 0);
	Col.PaletteIndex = 1;
	for (i = 0; i < 10; i++)
	{
		Graphics_DrawLineXYXY(0, _Number * 10 + i, 240, _Number * 10 + i, Col);
	}
	Graphics_SwapScreens();

//	while(1);	// Stay here.
}

// ----
// Call this inplace of an __assume statement - such as in 
// an 'undefined' switch statement.
void	Debug_NoSuchChoice(CHAR*	_File, LONG	_Line, CHAR*	_Msg)
{	
	sprintf(Debug_Buffer, "%s %d %s", _File, _Line, _Msg);
//	AGBPrint(_Msg);
	Debug_ErrorBar(0);
}
