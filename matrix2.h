//take the red pill............................................

#ifndef _MATRIX2_H_
#define _MATRIX2_H_

#include	"Vector2.h"
#if 0
typedef
struct _MATRIX2
{
	VECTOR2 C[2];
}
MATRIX2;


/* * * * *
 * OK this is a MATRIX2 type, It'll help with traslations and defining rigid
 * body physics.
 *
 * I'm going to try to do as much as as possible in inline functions.....
 *
 * Oh the MATRIX2 is in [column][row] format which is slightly different than usual.
 * * * * */


//checks equality between maticies
BOOL 	MIsEqual(MATRIX2 a, MATRIX2 b);

//Check if One MATRIX22 is not equal to another
BOOL	MIsNotEqual(MATRIX2 a, MATRIX2 b);

//Make one MATRIX22 equal to another
void	Mequ(MATRIX2 a, MATRIX2 b);

//add one MATRIX2 to another
void	Madd(MATRIX2 a, MATRIX2 b);

//subtract one MATRIX2 from another
void	Msub(MATRIX2 a, MATRIX2 b);

//multiply one MATRIX2 by another
void	Mmul(MATRIX2 a, MATRIX2 b);


//divide one MATRIX2 by another
void	Mdiv(MATRIX2 a, MATRIX2 b);
//Same as the above functions but these will return a MATRIX2
MATRIX2	MRetAdd(MATRIX2 a, MATRIX2 b);

MATRIX2	MRetSub(MATRIX2 a, MATRIX2 b);

MATRIX2	MRetMul(MATRIX2 a, MATRIX2 b);

MATRIX2	MRetDiv(MATRIX2 a, MATRIX2 b);

//Do MATRIX2 calulations using Scalar quantities
void	MAddSca(MATRIX2 a, SCALAR n);

void	MSubSca(MATRIX2 a, SCALAR n);

void	MMulSca(MATRIX2 a, SCALAR n);

void	MDivSca(MATRIX2 a, SCALAR n);

//The same but these will return a MATRIX2
MATRIX2	MRetAddSca(MATRIX2 a, SCALAR n);

MATRIX2	MRetSubSca(MATRIX2 a, SCALAR n);

MATRIX2	MRetMulSca(MATRIX2 a, SCALAR n);
MATRIX2	MRetDivSca(MATRIX2 a, SCALAR n);

//Calculations for modiying a MATRIX2 give a VECTOR2.
void	MAddVec(MATRIX2 a, VECTOR2 v);

void	MSubVec(MATRIX2 a, VECTOR2 v);

void	MMulVec(MATRIX2 a, VECTOR2 v);

void	MDivVec(MATRIX2 a, VECTOR2 v);

//The same but these will return a MATRIX2 instead
MATRIX2	MRetAddVec(MATRIX2 a, VECTOR2 v);

MATRIX2	MRetSubVec(MATRIX2 a, VECTOR2 v);

MATRIX2	MRetMulVec(MATRIX2 a, VECTOR2 v);

MATRIX2	MRetDivVec(MATRIX2 a, VECTOR2 v);

VECTOR2	VRetAddMat(VECTOR2 a, MATRIX2 m);
//this returns a version of the MATRIX2 that was passed in with all the column turned
// on thier side.... what fun hey....
MATRIX2	Mtranspose(MATRIX2 a);

//does something or other I'm sure of it....
//SCALAR	Mdeterminant(MATRIX2 a);

//MATRIX2 inverse
MATRIX2	Minverse(MATRIX2 a);

//this orthonormalisies my MATRIX2.. i.e I pass in a MATRIX2 and it makes sure that no matter
//direction it is orientated to it all the vertecies will be perpendicular to each other.
//void	MOrthonormalizeOrientation( MATRIX2 Orientation );
#endif
#endif