#include	"Vector2.h"

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

//checks wether two VECTOR2s are exactly equal
BOOL	VIsEqual(VECTOR2 a, VECTOR2 b){ return( (a.x == b.x) && (a.y == b.y) );};

//checks wether two VECTOR2s have differing values
BOOL	VIsNotEqual(VECTOR2 a, VECTOR2 b){ return( (a.x != b.x) || (a.y != b.y));};

//Adds two VECTOR2s together
void	Vadd(VECTOR2 a, VECTOR2 b){ a.x += b.x; a.y += b.y;};

//subtracts one VECTOR2 from another
void	Vsub(VECTOR2 a, VECTOR2 b){ a.x -= b.x; a.y -= b.y;};

//mutiplies one VECTOR2 by another
void	Vmul(VECTOR2 a, VECTOR2 b){ a.x = fpMul(a.x,b.x); a.y = fpMul(a.y,b.y);};

//divides one VECTOR2 by another
void	Vdiv(VECTOR2 a, VECTOR2 b){ a.x = fpDiv(a.x,b.x); a.y= fpDiv(a.y,b.y);};

//Negates a VECTOR2... i.e reverses the sign
void	Vneg(VECTOR2 a){a.x = -a.x; a.y = -a.y;};

//Makes one VECTOR2 "a" equal to "b"
void	Vequ(VECTOR2 a, VECTOR2 b){a.x = b.x; a.y = b.y;};

//returns the inverse of a VECTOR2
VECTOR2	VRetNeg(VECTOR2 a){VECTOR2 temp; Vequ(temp, a); Vneg(temp); return temp;};


/* * * * 
 * These function do the same as above but return the values as a VECTOR2 instead of 
 * putting the product into a;
 * * * */

//returns the value of two VECTOR2s added together
VECTOR2	VRetAdd(VECTOR2 a, VECTOR2 b){	VECTOR2 temp;			
										temp.x = (a.x + b.x);	
										temp.y = (a.y + b.y);	
										return temp;};

//returns the value of a - b
VECTOR2	VRetSub(VECTOR2 a, VECTOR2 b){	VECTOR2 temp;			
										temp.x = (a.x - b.x);	
										temp.y = (a.y - b.y);	
										return temp;};

//returns the values of a * b
VECTOR2	VRetMul(VECTOR2 a, VECTOR2 b){	VECTOR2 temp;			
										temp.x = fpMul(a.x,b.x);	
										temp.y = fpMul(a.y,b.y);		
										return temp;};

//returns the value of a / b
VECTOR2	VRetDiv(VECTOR2 a, VECTOR2 b){	VECTOR2 temp;			
										temp.x = fpDiv(a.x,b.x);	
										temp.y = fpDiv(a.y,b.y);	
										return temp;};

/* * * * * 
 * Ok these functions will adjust a VECTOR2 by a scalar value
 * This is applied to all the parts of a VECTOR2.
 * * * * */

//adds a value to a VECTOR2.. 
void	VAddSca(VECTOR2 a, SCALAR n){a.x += n; a.y += n;};

//subs a value from a VECTOR2
void	VSubSca(VECTOR2 a, SCALAR n){a.x -= n; a.y -= n;};

//multiplies a VECTOR2 by a value
void	VMulSca(VECTOR2 a, SCALAR n){a.x= fpMul(a.x,n); a.y= fpMul(a.y,n);};

//divides a VECTOR2 by a value
void	VDivSca(VECTOR2 a, SCALAR n){a.x= fpDiv(a.x,n); a.y= fpDiv(a.y,n);};

/* * * * *
 * These functions do the same as above but return the value
 * Instead of modifying VECTOR2 a
 * * * * */

//adds a scalar value to a VECTOR2 and returns the value
VECTOR2	VRetAddSca(VECTOR2 a, SCALAR n){	VECTOR2 temp;			
											temp.x = a.x + n;		
											temp.y = a.y + n;			
											return temp;};

//subtracts a scalar value from a VECTOR2 and returns the value
VECTOR2	VRetSubSca(VECTOR2 a, SCALAR n){	VECTOR2 temp;			
											temp.x = a.x - n;		
											temp.y = a.y - n;			
											return temp;};

//multiplies a VECTOR2 by a scalar value and returns
VECTOR2	VRetMulSca(VECTOR2 a, SCALAR n){	VECTOR2 temp;			
											temp.x = fpMul(a.x,n);		
											temp.y = fpMul(a.y,n);				
											return temp;};

//divides a VECTOR2 by a scalar and returns
VECTOR2	VRetDivSca(VECTOR2 a, SCALAR n){	VECTOR2 temp;			
											temp.x = fpDiv(a.x,n);		
											temp.y = fpDiv(a.y,n);				
											return temp;};

/* * * * *
 * Ok that does it for the simple functions.
 * The functions that follow are all very useful.... I'm sure they must be
 * * * * */
//return VECTOR2( y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x );

//Returns a Scalar dot product
SCALAR	Vdot(VECTOR2 a, VECTOR2 b){return( fpMul(a.x,b.x) + fpMul(a.y,b.y));};

//Returns the length of a VECTOR2
SCALAR	Vlength(VECTOR2 a){	return (fpSqrt2(Vdot(a,a)));};

//Returns a unit VECTOR2
VECTOR2	Vunit(VECTOR2 a){ return (VRetDivSca(a,Vlength(a)));};

//make a VECTOR2 a unit VECTOR2
void	Vnormalise(VECTOR2 a){ VDivSca(a, Vlength(a));};
VECTOR2	VRetnormalise(VECTOR2 a){ return (VRetDivSca(a, Vlength(a)));};

//returns true if a VECTOR2 is nearly equal to another
BOOL	VIsNearlyEqual(VECTOR2 a, VECTOR2 b, SCALAR e){return ( abs(a.x - b.x)<e && abs(a.y - b.y)<e);};

void	VSetVec(VECTOR2 a, SCALAR x, SCALAR y)
{
	a.x = x;
	a.y = y;
};

SCALAR PerpDotProduct( VECTOR2 A, VECTOR2 B )
{
	return( fpMul(A.x,B.x) - fpMul(A.y,B.y) );
};

VECTOR2 GetPerpendicular( VECTOR2 A )
{
	VECTOR2 temp;
	temp.x = -A.y;
	temp.y = A.x;
	return temp;
};









