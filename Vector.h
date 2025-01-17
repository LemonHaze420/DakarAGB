#ifndef	_VECTOR_H_
#define _VECTOR_H_

#include "Fixed.h"
#include <AgbTypes.h>
//#include "BasicTypes.h"

typedef
struct	_VECTOR
{
	SCALAR	x;
	SCALAR	y;
	SCALAR	z;
}
VECTOR;

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
BOOL	VIsEqual(VECTOR a, VECTOR b);

//checks wether two vectors have differing values
BOOL	VIsNotEqual(VECTOR a, VECTOR b);

//Adds two vectors together
void	Vadd(VECTOR a, VECTOR b);
//subtracts one vector from another
void	Vsub(VECTOR a, VECTOR b);
//mutiplies one vector by another
void	Vmul(VECTOR a, VECTOR b);

//divides one vector by another
void	Vdiv(VECTOR a, VECTOR b);

//Negates a vector... i.e reverses the sign
void	Vneg(VECTOR a);

//Makes one vector "a" equal to "b"
void	Vequ(VECTOR a, VECTOR b);

//returns the inverse of a vector
VECTOR	VRetNeg(VECTOR a);

void	VSetVec(VECTOR a, SCALAR x, SCALAR y, SCALAR z);


/* * * * 
 * These function do the same as above but return the values as a vector instead of 
 * putting the product into a;
 * * * */

//returns the value of two vectors added together
VECTOR	VRetAdd(VECTOR a, VECTOR b);

//returns the value of a - b
VECTOR	VRetSub(VECTOR a, VECTOR b);
//returns the values of a * b
VECTOR	VRetMul(VECTOR a, VECTOR b);

//returns the value of a / b
VECTOR	VRetDiv(VECTOR a, VECTOR b);

/* * * * * 
 * Ok these functions will adjust a vector by a scalar value
 * This is applied to all the parts of a vector.
 * * * * */

//adds a value to a vector.. 
void	VAddSca(VECTOR a, SCALAR n);

//subs a value from a vector
void	VSubSca(VECTOR a, SCALAR n);

//multiplies a vector by a value
void	VMulSca(VECTOR a, SCALAR n);

//divides a vector by a value
void	VDivSca(VECTOR a, SCALAR n);

/* * * * *
 * These functions do the same as above but return the value
 * Instead of modifying Vector a
 * * * * */

//adds a scalar value to a vector and returns the value
VECTOR	VRetAddSca(VECTOR a, SCALAR n);

//subtracts a scalar value from a vector and returns the value
VECTOR	VRetSubSca(VECTOR a, SCALAR n);

//multiplies a vector by a scalar value and returns
VECTOR	VRetMulSca(VECTOR a, SCALAR n);
//divides a vector by a scalar and returns
VECTOR	VRetDivSca(VECTOR a, SCALAR n);

/* * * * *
 * Ok that does it for the simple functions.
 * The functions that follow are all very useful.... I'm sure they must be
 * * * * */
//return VECTOR( y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x );

//This returns the cross product of two vectors
VECTOR	Vcross(VECTOR a, VECTOR b);
//Returns a Scalar dot product
SCALAR	Vdot(VECTOR a, VECTOR b);

//Returns the length of a vector
SCALAR	Vlength(VECTOR a);

//Returns a unit vector
VECTOR	Vunit(VECTOR a);

//make a vector a unit vector
void	Vnormalise(VECTOR a);
VECTOR	VRetnormalise(VECTOR a);

//returns true if a vector is nearly equal to another
BOOL	VIsNearlyEqual(VECTOR a, VECTOR b, SCALAR e);

typedef VECTOR	VPOINT;

typedef
struct	_TRI
{
	VPOINT	v1;
	VPOINT	v2;
	VPOINT	v3;
}
TRI;

typedef
struct	_HUNK
{
	unsigned char HeightData[192][192];
	unsigned unsigned int ColourData[192][192];
}
HUNK;

#endif







