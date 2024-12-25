// FILE:		Globals.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:

// INCLUDES:
#include	"BasicTypes.h"
#include	"BasicDefines.h"
#include	"Agb.h"

CHAR		Buffer[256];	// A global buffer
COLOUR		Col;

u16			TrackPalette[256]; //the tracks palette
unsigned char Viewport[1024]; //the array to keep track data in;

// ----
// Array index to BG control registers
const		UHWORD				*BGCntRegs[4]		=	{
															(UHWORD*)REG_BG0CNT,
															(UHWORD*)REG_BG1CNT,
															(UHWORD*)REG_BG2CNT,
															(UHWORD*)REG_BG3CNT
														};

// X-offset registers
const		UHWORD				*BGXOffsetRegs[4]	=	{
															(UHWORD*)REG_BG0HOFS,
															(UHWORD*)REG_BG1HOFS,
															(UHWORD*)REG_BG2HOFS,
															(UHWORD*)REG_BG3HOFS
														};
// Y-offset registers
const		UHWORD				*BGYOffsetRegs[4]	=	{
															(UHWORD*)REG_BG0VOFS,
															(UHWORD*)REG_BG1VOFS,
															(UHWORD*)REG_BG2VOFS,
															(UHWORD*)REG_BG3VOFS
														};

// If I knew what these were for I'd comment them...
const		UHWORD				*BGXLRegs[4]		=	{
															(UHWORD*)NULL,
															(UHWORD*)NULL,
															(UHWORD*)REG_BG2X_L,
															(UHWORD*)REG_BG3X_L
														};

const		UHWORD				*BGYLRegs[4]		=	{
															(UHWORD*)NULL,
															(UHWORD*)NULL,
															(UHWORD*)REG_BG2Y_L,
															(UHWORD*)REG_BG3Y_L
														};

const		UHWORD				*BGXHRegs[4]		=	{
															(UHWORD*)NULL,
															(UHWORD*)NULL,
															(UHWORD*)REG_BG2X_H,
															(UHWORD*)REG_BG3X_H
														};

const		UHWORD				*BGYHRegs[4]		=	{
															(UHWORD*)NULL,
															(UHWORD*)NULL,
															(UHWORD*)REG_BG2Y_H,
															(UHWORD*)REG_BG3Y_H
														};

const		UHWORD				*BGPARegs[4]		=	{
															(UHWORD*)NULL,
															(UHWORD*)NULL,
															(UHWORD*)REG_BG2PA,
															(UHWORD*)REG_BG3PA
														};

const		UHWORD				*BGPBRegs[4]		=	{
															(UHWORD*)NULL,
															(UHWORD*)NULL,
															(UHWORD*)REG_BG2PB,
															(UHWORD*)REG_BG3PB
														};

const		UHWORD				*BGPCRegs[4]		=	{
															(UHWORD*)NULL,
															(UHWORD*)NULL,
															(UHWORD*)REG_BG2PC,
															(UHWORD*)REG_BG3PC
														};

const		UHWORD				*BGPDRegs[4]		=	{
															(UHWORD*)NULL,
															(UHWORD*)NULL,
															(UHWORD*)REG_BG2PD,
															(UHWORD*)REG_BG3PD
														};
//struct MapStruct	Map[256][256];
