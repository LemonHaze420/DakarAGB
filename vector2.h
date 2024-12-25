#ifndef	_VECTOR2_H_
#define _VECTOR2_H_

#include "Fixed.h"
//#include "BasicTypes.h"



#if 0
typedef
struct	_VECTOR2
{
	SCALAR	x;
	SCALAR	y;
}
VECTOR2;

/* * * * * 
 * I'm going to do all these operators on vectors
 * as functions to start with. If we really need 
 * more speed then I shall covert some or all of them
 * to macros, but only after getting rid of nasty 
 * bugs.
 * * * * */

/* * * * *
 * One more note, I'm going to drop from our naming
 * convention in a desperate effort to speed coding time
 * All vector functions will be in this form
 * Vfunctionname. i.e. VAdd(VECTOR, VECTOR)
 *
 * This should hopefully save some time.
 * * * * */

//checks wether two vectors are exactly equal
BOOL	VIsEqual(VECTOR2 a, VECTOR2 b);

//checks wether two VECTOR2s have differing values
BOOL	VIsNotEqual(VECTOR2 a, VECTOR2 b);

//Adds two VECTOR2s together
void	Vadd(VECTOR2 a, VECTOR2 b);
//subtracts one VECTOR2 from another
void	Vsub(VECTOR2 a, VECTOR2 b);
//mutiplies one VECTOR2 by another
void	Vmul(VECTOR2 a, VECTOR2 b);

//divides one VECTOR2 by another
void	Vdiv(VECTOR2 a, VECTOR2 b);

//Negates a VECTOR2... i.e reverses the sign
void	Vneg(VECTOR2 a);

//Makes one VECTOR2 "a" equal to "b"
void	Vequ(VECTOR2 a, VECTOR2 b);

//returns the inverse of a VECTOR2
VECTOR2	VRetNeg(VECTOR2 a);

void	VSetVec(VECTOR2 a, SCALAR x, SCALAR y);


/* * * * 
 * These function do the same as above but return the values as a VECTOR2 instead of 
 * putting the product into a;
 * * * */

//returns the value of two VECTOR2s added together
VECTOR2	VRetAdd(VECTOR2 a, VECTOR2 b);

//returns the value of a - b
VECTOR2	VRetSub(VECTOR2 a, VECTOR2 b);
//returns the values of a * b
VECTOR2	VRetMul(VECTOR2 a, VECTOR2 b);

//returns the value of a / b
VECTOR2	VRetDiv(VECTOR2 a, VECTOR2 b);

/* * * * * 
 * Ok these functions will adjust a VECTOR2 by a scalar value
 * This is applied to all the parts of a VECTOR2.
 * * * * */

//adds a value to a VECTOR2.. 
void	VAddSca(VECTOR2 a, SCALAR n);

//subs a value from a VECTOR2
void	VSubSca(VECTOR2 a, SCALAR n);

//multiplies a VECTOR2 by a value
void	VMulSca(VECTOR2 a, SCALAR n);

//divides a VECTOR2 by a value
void	VDivSca(VECTOR2 a, SCALAR n);

/* * * * *
 * These functions do the same as above but return the value
 * Instead of modifying VECTOR2 a
 * * * * */

//adds a scalar value to a VECTOR2 and returns the value
VECTOR2	VRetAddSca(VECTOR2 a, SCALAR n);

//subtracts a scalar value from a VECTOR2 and returns the value
VECTOR2	VRetSubSca(VECTOR2 a, SCALAR n);

//multiplies a VECTOR2 by a scalar value and returns
VECTOR2	VRetMulSca(VECTOR2 a, SCALAR n);
//divides a VECTOR2 by a scalar and returns
VECTOR2	VRetDivSca(VECTOR2 a, SCALAR n);

/* * * * *
 * Ok that does it for the simple functions.
 * The functions that follow are all very useful.... I'm sure they must be
 * * * * */
//return VECTOR2( y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x );

//This returns the cross product of two VECTOR2s
VECTOR2	Vcross(VECTOR2 a, VECTOR2 b);
//Returns a Scalar dot product
SCALAR	Vdot(VECTOR2 a, VECTOR2 b);

//Returns the length of a VECTOR2
SCALAR	Vlength(VECTOR2 a);

//Returns a unit VECTOR2
VECTOR2	Vunit(VECTOR2 a);

//make a VECTOR2 a unit VECTOR2
void	Vnormalise(VECTOR2 a);
VECTOR2	VRetnormalise(VECTOR2 a);

//returns true if a VECTOR2 is nearly equal to another
BOOL	VIsNearlyEqual(VECTOR2 a, VECTOR2 b, SCALAR e);

SCALAR PerpDotProduct(VECTOR2 A, VECTOR2 B );

VECTOR2 GetPerpendicular(VECTOR2 A );

typedef VECTOR2	 VPOINT;
#endif
#endif







