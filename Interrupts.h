// FILE:		Interrupts.h
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

#ifndef	_INTERRUPTS_H_
#define	_INTERRUPTS_H_

// INCLUDES:
#include	"Agb.h"
#include	"BasicTypes.h"
#include	"BasicDefines.h"

// ----
// Number of interrupts.
#define	NUMBER_OF_INTERRUPTS	14

// ----
// Type definition for an enumerated type.
typedef
enum		// Enumeration of possible interrupts. 
_EInterrupt	// Value indicates bit index into IE and IF registers.
{
	EInterrupt_VerticalBlank	= 0,
	EInterrupt_HorizontalBlank	= 1,
	EInterrupt_VCounterMatch	= 2,
	EInterrupt_Timer0			= 3,
	EInterrupt_Timer1			= 4,
	EInterrupt_Timer2			= 5,
	EInterrupt_Timer3			= 6,
	EInterrupt_Comms			= 7,	// Communications (Serial, JOY Bus, UART).
	EInterrupt_DMA0				= 8,
	EInterrupt_DMA1				= 9,
	EInterrupt_DMA2				= 10,
	EInterrupt_DMA3				= 11,
	EInterrupt_Key				= 12,
	EInterrupt_GamePack			= 13
}
EInterrupt;

// ----
// Type definition for a function pointer.
typedef void (*InterruptCallback)(void);

// ----
// Interrupts_DummyCallback updates this value to reflect which 
// interrupts are active. If you replace Interrupts_DummyCallback
// with a callback of your own it is up to you to set the bit 
// within this value correctly. 
VUHWORD	Interrupts_Check;	

// ----
// A dummy callback function for use in place of an assigned callback function.
void	Interrupts_DummyCallback();

// ----
// Initialise the interrupt table, etc.
void	Interrupts_Init();

// ----
// Enable or disable all interrupts
// 0 - disable.
// 1 - enable.
void	Interrupts_SetState(INT	_State);

// ----
// Allows the masking or activation of individual interrupts.
// _Interrupt is an enumerated type. Set header file for declaration.
// 0 - disables interrupt notification.
// 1 - enables		"			"
void	Interrupts_SetInterruptMask(EInterrupt	_Interrupt, INT	_State);

// ----
// Read the state for each interrupt.
// FALSE indicates that the interrupt has NOT been triggered.
// TRUE indicates that the interrupt has been triggered.
// The interrupt flag is not automatically cleared.
BOOL	Interrupts_GetInterruptState(EInterrupt	_Interrupt);

// ----
// Clear a particular interrupt flag.
void	Interrupts_ClearInterruptState(EInterrupt	_Interrupt);

// ----
// Clear all interrupt flags.
void	Interrupts_ClearAllInterruptStates();

// ----
// Set interrupt callback for a particular interrupt.
// Passing an non-NULL value for _CallbackFunction assigns that 
// address as the interrupt's callback function, and automatically
// enables notification for the interrupt. 
// Passing NULL for _CallbackFunction will remove a callback for the
// particular interrupt, but does NOT clear notification.
void	Interrupts_SetCallback(EInterrupt		_Interrupt,
							  InterruptCallback	_CallbackFunction);

// ----
// Copy interrupt handle to RAM for faster interrupt handling.
UHWORD	InterruptMainBuffer[0x200];	// This is the buffer that the code will be copied into.
void	Interrupts_CopyInterruptHandlerToCPURAM();


// ----
// Useful interrupt handling functions.
// ----

// ----
// Wait for the vertical blank period to end.
void Interrupts_WaitVerticalBlank();


#endif