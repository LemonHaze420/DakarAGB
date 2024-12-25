// FILE:		Dakar.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// INCLUDES:
#include	"Dakar.h"

#include	"Agb.h"	
#include	"BasicTypes.h"	// Types
#include	"BasicDefines.h"// Defines
#include	"Debug.h"		// Debugging tools
#include	"Macros.h"		// Useful macros.

#include	"Platform.h"	// Platform abstraction layer.
#include	"Interrupts.h"	// Interrupt handling
#include	"Graphics.h"	// Graphics functions.
#include	"Controls.h"	// Control functions.
#include	"Sound.h"		// Sound functions.

#include	"Extern.h"		// Access to data.
#include	"share.h"		// Temp  code - this shall be replaced / moved.	(Nothing to do with shared data!!!)

// ----
// FUNCTION:	main
// PARAMETERS:	<none>
// STATUS:		Prototype.
// VERSION:		0.1
// COMMENT:		Welcome to Dakar for Game Boy Advanced.
//				This function is the first code reached after the 
//				loader. The code first initialises the system, system
//				objects. Secondly it creates the game object, 
//				initialises it and sets it running. Finally, the code 
//				closes the system down - if it should ever have to. 
//				
//				All code is subject to change.
INT AGBmain()
{
	// ----
	// Plan of action.
	// 1. Initialise the platform
	//	a. Clear all RAM.
	
	// 2. Initialise the interrupts.
	//	a. Stop all interrupts.
	
	// 3. Initialise Graphics, Sound, and Control systems.
	//	a. Graphics
	//	b. Sound.
	//	c. Controls.
	
	// 4. Setup interrupts.
	//	a. Copy interrupt handler to RAM, as it is quicker that way.
	//	b. Set-up vertical blank interrupt.
	//	c. Others (working on this).
	//	d. Activate interrupts.

	// 5. Initialise the game.
	//	a. Initialise Dakar_StateTable - very important that this is done!
	//	b. Set the game running.
	
	// 6. Shutdown or error handling.
	//	a. Not sure yet.

	// ----
	// 1. Initialise the platfrom.
	if (!Platform_Init())
		Platform_Error();

	// ----
	// 2. Stop interrupts.
	Interrupts_Init();

	// ----
	// 3a, b, c. Init systems.
	Graphics_Init(1);	// Eventually want mode 1 or 2.
	Sound_Init();
	Controls_Init();

	// ----
	// 4a, b, c, d. Setup interrupts.
	Interrupts_CopyInterruptHandlerToCPURAM();							// Copy handler to memory.
//	Interrupts_SetCallback(EInterrupt_VerticalBlank, bg_v_blank_intr);	// Assign callback (and enable particular interrupt).
//	Interrupts_SetInterruptMask(EInterrupt_Key, TRUE);					// Enable key interrupt
	Interrupts_SetState(TRUE);											// And go...

	// ----
	// 5. Initialise the Dakar_StateTables. 
	//	a. The state tables are arrays of addresses of function that 
	//	   determine the game flow dependent on the game state.
	Dakar_InitStateTables();

	// 5b. Set the game running.
	while (Dakar_StateTable[Dakar_State]());

	// ----
	// 6. Not sure how we got here. Must be an error.
	Platform_Error();
}

