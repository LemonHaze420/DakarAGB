// FILE:		Interrupts.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// INCLUDES:
#include	"Interrupts.h"
#include	"Agb.h"
#include	"BasicTypes.h"
#include	"BasicDefines.h"
#include	"Macros.h"
#include	"Debug.h"

// ----
// Need to access a (assembly) function in the start-up code.
extern	void InterruptMain(void);

// ----
// Interrupt Table
InterruptCallback InterruptTable[NUMBER_OF_INTERRUPTS];

// ----
// A dummy callback function for use in place of an assigned callback function.
void	Interrupts_DummyCallback()
{
	Interrupts_Check	= *(VUHWORD*)REG_IF;
}

// ----
// Initialise the interrupt table, etc.
void	Interrupts_Init()
{
	INT	i;
	// Clear all interrupt flags.
	*(VUHWORD*)REG_IME	= 0;
	*(VUHWORD*)REG_IE	= 0;
	*(VUHWORD*)REG_IF	= 0;
	*(VUHWORD*)REG_STAT	= 0;
	Interrupts_Check	= 0;

	for (i = NUMBER_OF_INTERRUPTS; i--;)
	{
		InterruptTable[i] = Interrupts_DummyCallback;
	}
}

// ----
// Enable or disable all interrupts
// 0 - disable.
// 1 - enable.
void	Interrupts_SetState(INT	_State)
{
	*(VUHWORD*)REG_IME = _State & 0x01;
}

// ----
// Allows the masking or activation of individual interrupts.
// _Interrupt is an enumerated type. Set header file for declaration.
// 0 - disables interrupt notification.
// 1 - enables		"			"
void	Interrupts_SetInterruptMask(EInterrupt	_Interrupt, INT	_State)
{
	if (_State)
	{
		SET_BIT_AT_ADDRESS	(REG_IE, VUHWORD, (UHWORD)_Interrupt);
	}
	else
	{
		CLEAR_BIT_AT_ADDRESS(REG_IE, VUHWORD, (UHWORD)_Interrupt);
	}
}

// ----
// Read the state for each interrupt.
// FALSE indicates that the interrupt has NOT been triggered.
// TRUE indicates that the interrupt has been triggered.
// The interrupt flag is not automatically cleared.
BOOL	Interrupts_GetInterruptState(EInterrupt	_Interrupt)
{
	return GET_BIT_AT_ADDRESS(REG_IF, VUHWORD, (UHWORD)_Interrupt);
}

// ----
// Clear a particular interrupt flag.
void	Interrupts_ClearInterruptState(EInterrupt	_Interrupt)
{
	CLEAR_BIT_AT_ADDRESS(REG_IF, VUHWORD, (UHWORD)_Interrupt);
}

// ----
// Clear all interrupt flags.
void	Interrupts_ClearAllInterruptStates()
{
	*(VUHWORD*)REG_IF	= 0;	// Warning: Bits 14, 15 aren't to be used by us!
	Interrupts_Check	= 0;
}

// ----
// Set interrupt callback for a particular interrupt.
// Passing an non-NULL value for _CallbackFunction assigns that 
// address as the interrupt's callback function, and automatically
// enables notification for the interrupt. 
// Passing NULL for _CallbackFunction will remove a callback for the
// particular interrupt, but does NOT clear notification.
void	Interrupts_SetCallback(	EInterrupt			_Interrupt,
								InterruptCallback	_CallbackFunction)
{
	if (_CallbackFunction)
	{
		InterruptTable[(UHWORD)_Interrupt] = _CallbackFunction;
		Interrupts_SetInterruptMask(_Interrupt, TRUE);

		if (_Interrupt == EInterrupt_VerticalBlank)
		{
			*(VUHWORD*)REG_STAT  |= STAT_V_BLANK_IF_ENABLE;
		}

		if (_Interrupt == EInterrupt_HorizontalBlank)
		{
			*(VUHWORD*)REG_STAT  |= STAT_H_BLANK_IF_ENABLE;
		}
	}
	else
	{
		InterruptTable[(UHWORD)_Interrupt] = Interrupts_DummyCallback;
	}
}

// ----
// Copy interrupt handle to RAM for faster interrupt handling.
void	Interrupts_CopyInterruptHandlerToCPURAM()
{
	// DMA copy function to memory, and assign INTR_VECTOR_BUF. 
	DmaCopy(3, InterruptMain, InterruptMainBuffer, sizeof(InterruptMainBuffer), 32);
    IntrAddrSet(InterruptMainBuffer);	// AgbMacro call.
}


// ----
// Useful interrupt handling functions.
// ----

// ----
// Wait for the vertical blank period to end.
void Interrupts_WaitVerticalBlank()
{
    CLEAR_BIT(Interrupts_Check, (INT)EInterrupt_VerticalBlank);
	CLEAR_BIT_AT_ADDRESS(REG_IF, VUHWORD, V_BLANK_INTR_FLAG);

	while (TRUE)
	{
		if (Interrupts_Check & V_BLANK_INTR_FLAG)
			break;
   
		Halt();		// Halt the CPU to save power. (i.e. sleep until any interrrupt is triggered).
    }
}
