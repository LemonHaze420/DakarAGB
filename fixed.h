#ifndef _FIXED_H_
#define _FIXED_H_

#include "BasicTypes.h"
#include "macros.h"

// handy macros
#define sign(a) (((a)<0) ? -1 : (a)>0 ? 1 : 0)


// Integer math

// Multiply to 32 bit numbers giving a 64 bit
// result then divide the 64 bit number by a 32 
// bit value and return the result.

LONG
mulDiv(LONG value, LONG mulBy, LONG divBy);
#pragma aux mulDiv = \
    "imul   ecx" \
    "idiv   ebx" \
    parm [eax] [ecx] [ebx]\
    modify [edx] \
    value [eax];

extern LONG iSqrt(LONG value);

// fixed point math

typedef LONG fp14;

// Multiply two 18.14 fixed point numbers giving
// a 18.14 fixed point result.



#define fpDiv(d1, d2) ( (d1 << 14) / d2)
/*
_asm
{
}

#pragma aux fpDiv = \
    "cdq" \
    "shld   edx, eax, 14" \
    "sal    eax,14" \
    "idiv   ebx" \
    parm [eax] [ebx]\
    modify [edx] \
    value [eax];
*/

// Divide two 18.14 fixed point numbers giving
// a 18.14 fixed point result.
					
#define fpMul(m1, m2) ( (m1 * m2) >> 14)
// Add and subtract fixed point numbers. :-)


#define fpAdd(a1, a2) ((a1) + (a2))
#define fpSub(s1, s2) ((s1) - (s2))


// Convert an integer to n N.14 fixed point 
// number and back.


#define int2fp(x) ((x) << 14)
#define fp2int(x) ((x) >> 14)


// Get the fractional part of an N.14 fixed point
// number.

#define fpFract(x) ((x) & 0x3fff)


// Convert a N.14 fixed point number to a
// DOUBLE and back. Handy for printing and for 
// those times when you really do want to work
// with floating point values.


#define fp2float(x) (((DOUBLE)(x)) / (1 << 14))
#define float2fp(x) ((fp14) (((DOUBLE)x) * (1 << 14)))


// handy fixed point constants


#define fpZero int2fp(0)
#define fpOne int2fp(1)
#define fpTwo int2fp(2)
#define fpHalf (1 << 13)

// Table based fixed point sine and cosine 
// functions.


extern fp14 sine[];
extern fp14 cosine[];

#define fpSin(x) (sine[(x) & 0xff])
#define fpCos(x) (cosine[(x) & 0xff])

#define fpSqrt(x) fpSqrt2(x)
extern fp14 fpSqrt1(fp14 value);
extern fp14 fpSqrt2(fp14 value);

typedef	fp14 SCALAR;

#endif
