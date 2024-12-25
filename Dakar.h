// FILE:		Dakar.h
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// COMMENTS:	Wait.

// INCLUDES:
#include	"Agb.h"	
#include	"BasicTypes.h"	// Types
#include	"BasicDefines.h"// Defines
#include	"Debug.h"		// Debugging tools
#include	"Macros.h"		// Useful macros.
#include	"Car.h"
#include	"TrackData.h"

#include	"Map.h"

// ----
// Maximum number of game states.
#define	NUMBER_OF_GAME_STATES	64
#define	NUMBER_OF_MENU_EFFECTS	4
#define	MAX_NUMBER_OF_POLYS		400

// ----
// A type definition for all possible game states.
typedef
enum
_EDakarState
{
	EDakarState_Start		= 0,
	EDakarState_Splash		= 1,

	EDakarState_MenuInit	= 20,
	EDakarState_Menu		= 21,

	EDakarState_GameInit	= 40,
	EDakarState_Game		= 41
}
EDakarState;

// ----
typedef
struct
_MenuEffectStruct
{
	UBYTE	Effect;
	SBYTE	X;
}
MenuEffectStruct;

// ----
// Type definition for a function pointer.
typedef BOOL (*DakarFunction)(void);
typedef	void (*TriangleFunction)(POINT*, COLOUR*, INT);

// ----
// Variables
// ----

// ----
// Menu variable declaration.
INT					Dakar_MenuCurrPos;
INT					Dakar_MenuPrevPos;
MenuEffectStruct	Dakar_MenuEffect[NUMBER_OF_MENU_EFFECTS];

// ----
// In-game variables




// Pure track data.
extern const UBYTE*	Dakar_TrackArrayList[DAKAR_NUMBER_OF_TRACKS];					// Hardcoded array that stores the addresses of each of the track splines.
extern const UBYTE	Dakar_TileHeightArray[HEIGHT_TILE_COUNT * DAKAR_TILE_COUNT];	// Array of hard coded track height data. Each tile is 32*32 (or 1024 bytes).
extern const USHORT	Dakar_TileColourArray[COLOUR_TILE_COUNT * DAKAR_TILE_COUNT];	// Array of hard coded track colour data. Each tile is 16*16 (or 256 bytes).

UBYTE				Dakar_TrackNumber;			// Current track number.
UBYTE*				Dakar_TrackArrayPointer;	// Pointer set to point to some track array stored in ROM.
ULONG				Dakar_TrackPosition;		// Index into array pointed to above.

// Rendering
// This is the final render pool. 
// Data is pulled out from here and rendered.
UBYTE				Dakar_GraphicsMapHeight[HEIGHT_TILE_COUNT * 4]; 
USHORT				Dakar_GraphicsMapColour[COLOUR_TILE_COUNT * 4]; 

// Where we are swimming in the little pool.
INTVECTOR			Dakar_ViewDirection;
INTVECTOR			Dakar_ViewPosition;

// Car - game.
BOOL				Dakar_ContinueRace;	// Set to false to exit race code.
A_CAR				playersCar;

// ----
// An array of functions to call.
DakarFunction		Dakar_StateTable[NUMBER_OF_GAME_STATES];
EDakarState			Dakar_State;


// ----
// Function declararions.
// ----

// ---- 
// Set things up.
void	Dakar_InitStateTables();

// ----
// Vertical blank interrupt handler for the menu system
void	Dakar_MenuVBlankHandler();

// ----
// In-game vertical blank routines. 
void	Dakar_GameVerticalBlank();

// ----
// In-game horizontal blank routines.
void	Dakar_GameHorizontalBlank();

// ----
// Temp, for prototyping.
void	Dakar_SetCamera();

// ----
// Setup the rendering process, which will be 
// controlled by the two functions above.
void	Dakar_SetUpRender();

// ----
// Actually render the frame and flip the buffer.
void	Dakar_Render();

//Draws the car.... duh
void	Dakar_GameDrawCar();

// ----
// Adds a polygon to the rendering list.
void	Dakar_AddTriangle(INT _X0, INT _Y0,
						  INT _X1, INT _Y1,
						  INT _X2, INT _Y2,
						  COLOUR	_Col);

// ----
// Text offest possibilities.
#define	TEXT_NORMAL			(0 << 0)
#define	TEXT_LEFT			(0 << 0)
#define	TEXT_RIGHT			(1 << 0)
#define	TEXT_CENTRED		(1 << 1)

// ----
// A string drawing routing specific to the menus. 
// This is only temporary as I have no idea where artwork will end up.
void	Dakar_MenuDrawString(	INT		_BG,
								INT		_X,
								INT		_Y, 
								CHAR*	_String,
								UBYTE	_Style);

// ----
// A string drawing routing specific to the game. 
void	Dakar_GameDrawString(INT	_X,
							 INT	_Y, 
							 CHAR*	_String,
							 UBYTE	_Style);

// ----
// Process any effects on the menu system
void	Dakar_MenuProcessEffects();

// ----
// Set an effect.
void	Dakar_MenuNotPossible(INT	_BG);


// ----
// Dakar game modes.
// ----

// ----
// Start things off - init display resolution, etc.
BOOL	Dakar_Start();

// ----
// Show splash screens / animations.
BOOL	Dakar_Splash();	

// ----
// Initialise the menu system, load graphics etc.
BOOL	Dakar_MenuInit();

// ----
// Run the menus. Stubs - as in Dakar_MenuMain() - would probably make this easier.
BOOL	Dakar_Menu();

// ----
// Initialise the in game data.
BOOL	Dakar_GameInit();

// ----
// Run the game. Again, stubs may help.
BOOL	Dakar_Game();

// Future use
/*
BOOL	Dakar_
BOOL	Dakar_
BOOL	Dakar_
BOOL	Dakar_
BOOL	Dakar_
BOOL	Dakar_
BOOL	Dakar_
*/



// ----
// Dakar data loading functions
// ----

// ----
// Load data for splash screen.
void	Dakar_LoadSplash();

// ----
// Load all the data for the game menu system.
void	Dakar_LoadMenu();

// ----
// Load in game data.
void	Dakar_LoadGame();
