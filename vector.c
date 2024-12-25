#include	"Vector.h"

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
BOOL	VIsEqual(VECTOR a, VECTOR b){ return( (a.x == b.x) && (a.y == b.y) && (a.z == b.z) );};

//checks wether two vectors have differing values
BOOL	VIsNotEqual(VECTOR a, VECTOR b){ return( (a.x != b.x) || (a.y != b.y) || (a.z != b.z) );};

//Adds two vectors together
void	Vadd(VECTOR a, VECTOR b){ a.x += b.x; a.y += b.y; a.z += b.z;};

//subtracts one vector from another
void	Vsub(VECTOR a, VECTOR b){ a.x -= b.x; a.y -= b.y; a.z -= b.z;};

//mutiplies one vector by another
void	Vmul(VECTOR a, VECTOR b){ a.x = fpMul(a.x,b.x); a.y = fpMul(a.y,b.y); a.z = fpMul(a.z,b.z);};

//divides one vector by another
void	Vdiv(VECTOR a, VECTOR b){ a.x = fpDiv(a.x,b.x); a.y= fpDiv(a.y,b.y); a.z = fpDiv(a.z,b.z);};

//Negates a vector... i.e reverses the sign
void	Vneg(VECTOR a){a.x = -a.x; a.y = -a.y; a.z = -a.z;};

//Makes one vector "a" equal to "b"
void	Vequ(VECTOR a, VECTOR b){a.x = b.x; a.y = b.y; a.z = b.z;};

//returns the inverse of a vector
VECTOR	VRetNeg(VECTOR a){VECTOR temp; Vequ(temp, a); Vneg(temp); return temp;};


/* * * * 
 * These function do the same as above but return the values as a vector instead of 
 * putting the product into a;
 * * * */

//returns the value of two vectors added together
VECTOR	VRetAdd(VECTOR a, VECTOR b){	VECTOR temp;			
										temp.x = (a.x + b.x);	
										temp.y = (a.y + b.y);	
										temp.z = (a.z + b.z);	
										return temp;};

//returns the value of a - b
VECTOR	VRetSub(VECTOR a, VECTOR b){	VECTOR temp;			
										temp.x = (a.x - b.x);	
										temp.y = (a.y - b.y);	
										temp.z = (a.z - b.z);
										return temp;};

//returns the values of a * b
VECTOR	VRetMul(VECTOR a, VECTOR b){	VECTOR temp;			
										temp.x = fpMul(a.x,b.x);	
										temp.y = fpMul(a.y,b.y);	
										temp.z = fpMul(a.z,b.z);	
										return temp;};

//returns the value of a / b
VECTOR	VRetDiv(VECTOR a, VECTOR b){	VECTOR temp;			
										temp.x = fpDiv(a.x,b.x);	
										temp.y = fpDiv(a.y,b.y);	
										temp.z = fpDiv(a.z,b.z);	
										return temp;};

/* * * * * 
 * Ok these functions will adjust a vector by a scalar value
 * This is applied to all the parts of a vector.
 * * * * */

//adds a value to a vector.. 
void	VAddSca(VECTOR a, SCALAR n){a.x += n; a.y += n; a.z += n;};

//subs a value from a vector
void	VSubSca(VECTOR a, SCALAR n){a.x -= n; a.y -= n; a.z -= n;};

//multiplies a vector by a value
void	VMulSca(VECTOR a, SCALAR n){a.x= fpMul(a.x,n); a.y= fpMul(a.y,n); a.z= fpMul(a.z,n);};

//divides a vector by a value
void	VDivSca(VECTOR a, SCALAR n){a.x= fpDiv(a.x,n); a.y= fpDiv(a.y,n); a.z= fpDiv(a.z,n);};

/* * * * *
 * These functions do the same as above but return the value
 * Instead of modifying Vector a
 * * * * */

//adds a scalar value to a vector and returns the value
VECTOR	VRetAddSca(VECTOR a, SCALAR n){	VECTOR temp;			
											temp.x = a.x + n;		
											temp.y = a.y + n;	
											temp.z = a.z + n;		
											return temp;};

//subtracts a scalar value from a vector and returns the value
VECTOR	VRetSubSca(VECTOR a, SCALAR n){	VECTOR temp;			
											temp.x = a.x - n;		
											temp.y = a.y - n;	
											temp.z = a.z - n;		
											return temp;};

//multiplies a vector by a scalar value and returns
VECTOR	VRetMulSca(VECTOR a, SCALAR n){	VECTOR temp;			
											temp.x = fpMul(a.x,n);		
											temp.y = fpMul(a.y,n);		
											temp.z = fpMul(a.z,n);		
											return temp;};

//divides a vector by a scalar and returns
VECTOR	VRetDivSca(VECTOR a, SCALAR n){	VECTOR temp;			
											temp.x = fpDiv(a.x,n);		
											temp.y = fpDiv(a.y,n);		
											temp.z = fpDiv(a.z,n);		
											return temp;};

/* * * * *
 * Ok that does it for the simple functions.
 * The functions that follow are all very useful.... I'm sure they must be
 * * * * */
//return VECTOR( y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x );

//This returns the cross product of two vectors
VECTOR	Vcross(VECTOR a, VECTOR b){	VECTOR temp;							
										temp.x = ( fpMul(a.y,b.z) - fpMul(a.z,b.y));	
										temp.y = ( fpMul(a.z,b.x) - fpMul(a.x,b.z));
										temp.z = ( fpMul(a.x,b.y) - fpMul(a.y,b.x));
										return temp;};

//Returns a Scalar dot product
SCALAR	Vdot(VECTOR a, VECTOR b){return( fpMul(a.x,b.x) + fpMul(a.y,b.y) + fpMul(a.z,b.z));};

//Returns the length of a vector
SCALAR	Vlength(VECTOR a){	return (fpSqrt2(Vdot(a,a)));};

//Returns a unit vector
VECTOR	Vunit(VECTOR a){ return (VRetDivSca(a,Vlength(a)));};

//make a vector a unit vector
void	Vnormalise(VECTOR a){ VDivSca(a, Vlength(a));};
VECTOR	VRetnormalise(VECTOR a){ return (VRetDivSca(a, Vlength(a)));};

//returns true if a vector is nearly equal to another
BOOL	VIsNearlyEqual(VECTOR a, VECTOR b, SCALAR e){ \
return ( abs(a.x - b.x)<e && abs(a.y - b.y)<e && abs(a.z - b.z)<e);};

void	VSetVec(VECTOR a, SCALAR x, SCALAR y, SCALAR z)
{
	a.x = x;
	a.y = y;
	a.z = z;
};









