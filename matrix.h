//take the red pill............................................

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include	"Vector.h"

typedef
struct _MATRIX
{
	VECTOR C[3];
}
MATRIX;


/* * * * *
 * OK this is a matrix type, It'll help with traslations and defining rigid
 * body physics.
 *
 * I'm going to try to do as much as as possible in inline functions.....
 *
 * Oh the matrix is in [column][row] format which is slightly different than usual.
 * * * * */


//checks equality between maticies
BOOL 	MIsEqual(MATRIX a, MATRIX b);

//Check if One matrix is not equal to another
BOOL	MIsNotEqual(MATRIX a, MATRIX b);

//Make one matrix equal to another
void	Mequ(MATRIX a, MATRIX b);

//add one matrix to another
void	Madd(MATRIX a, MATRIX b);

//subtract one matrix from another
void	Msub(MATRIX a, MATRIX b);

//multiply one matrix by another
void	Mmul(MATRIX a, MATRIX b);


//divide one matrix by another
void	Mdiv(MATRIX a, MATRIX b);
//Same as the above functions but these will return a MATRIX
MATRIX	MRetAdd(MATRIX a, MATRIX b);

MATRIX	MRetSub(MATRIX a, MATRIX b);

MATRIX	MRetMul(MATRIX a, MATRIX b);

MATRIX	MRetDiv(MATRIX a, MATRIX b);

//Do matrix calulations using Scalar quantities
void	MAddSca(MATRIX a, SCALAR n);

void	MSubSca(MATRIX a, SCALAR n);

void	MMulSca(MATRIX a, SCALAR n);

void	MDivSca(MATRIX a, SCALAR n);

//The same but these will return a MATRIX
MATRIX	MRetAddSca(MATRIX a, SCALAR n);

MATRIX	MRetSubSca(MATRIX a, SCALAR n);

MATRIX	MRetMulSca(MATRIX a, SCALAR n);
MATRIX	MRetDivSca(MATRIX a, SCALAR n);

//Calculations for modiying a matrix give a vector.
void	MAddVec(MATRIX a, VECTOR v);

void	MSubVec(MATRIX a, VECTOR v);

void	MMulVec(MATRIX a, VECTOR v);

void	MDivVec(MATRIX a, VECTOR v);

//The same but these will return a Matrix instead
MATRIX	MRetAddVec(MATRIX a, VECTOR v);

MATRIX	MRetSubVec(MATRIX a, VECTOR v);

MATRIX	MRetMulVec(MATRIX a, VECTOR v);

MATRIX	MRetDivVec(MATRIX a, VECTOR v);

VECTOR	VRetAddMat(VECTOR a, MATRIX m);

//this returns a version of the Matrix that was passed in with all the column turned
// on thier side.... what fun hey....
MATRIX	Mtranspose(MATRIX a);

//does something or other I'm sure of it....
SCALAR	Mdeterminant(MATRIX a);

//matrix inverse
MATRIX	Minverse(MATRIX a);

//this orthonormalisies my matrix.. i.e I pass in a matrix and it makes sure that no matter
//direction it is orientated to it all the vertecies will be perpendicular to each other.
void	MOrthonormalizeOrientation( MATRIX Orientation );

void	MCreateSkewSymmetricMatrix(MATRIX m, VECTOR v);

VECTOR	VRetMulVec(VECTOR v, MATRIX m);

VECTOR	x(MATRIX a);
VECTOR	y(MATRIX a);
VECTOR	z(MATRIX a);

void MRotateAroundX( MATRIX a,SCALAR n );

void MRotateAroundY(MATRIX a, SCALAR n );

void MRotateAroundZ(MATRIX a, SCALAR n );






VECTOR MtransformVectorToLocal( MATRIX a, VECTOR v );

VPOINT MtransformVectorToParent(MATRIX a, VECTOR v);

VPOINT	MTransformPointToLocal(MATRIX cf, VPOINT pos,  VPOINT p);

VPOINT  MTransformPointToParent(MATRIX cf,VPOINT pos, VPOINT p);

void	MTranslate(MATRIX cf,VPOINT pos, VECTOR v);
#endif