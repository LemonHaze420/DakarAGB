#include "Matrix2.h"
/* * * * *
 * OK this is a MATRIX2 type, It'll help with traslations and defining rigid
 * body physics.
 *
 * I'm going to try to do as much as as possible in inline functions.....
 *
 * Oh the MATRIX2 is in [column][row] format which is slightly different than usual.
 * * * * */


//checks equality between maticies
BOOL 	MIsEqual(MATRIX2 a, MATRIX2 b){ return(VIsEqual(a.C[0],b.C[0]) &&  VIsEqual(a.C[1],b.C[1]));};

//Check if One MATRIX2 is not equal to another
BOOL	MIsNotEqual(MATRIX2 a, MATRIX2 b){ return( !MIsEqual(a,b) );};

//Make one MATRIX2 equal to another
void	Mequ(MATRIX2 a, MATRIX2 b){	Vequ(a.C[0], b.C[0]); 
									Vequ(a.C[1], b.C[1]);};

//add one MATRIX2 to another
void	Madd(MATRIX2 a, MATRIX2 b){	Vadd(a.C[0], b.C[0]); 
									Vadd(a.C[1], b.C[1]); 
									};

//subtract one MATRIX2 from another
void	Msub(MATRIX2 a, MATRIX2 b){	Vsub(a.C[0], b.C[0]); 
									Vsub(a.C[1], b.C[1]); 
									};


//multiply one MATRIX2 by another
void	Mmul(MATRIX2 a, MATRIX2 b){	Vmul(a.C[0], b.C[0]); 
									Vmul(a.C[1], b.C[1]); 
									};


//divide one MATRIX2 by another
void	Mdiv(MATRIX2 a, MATRIX2 b){	Vdiv(a.C[0], b.C[0]); 
									Vdiv(a.C[1], b.C[1]); 
									};

//Same as the above functions but these will return a MATRIX2
MATRIX2	MRetAdd(MATRIX2 a, MATRIX2 b){	MATRIX2 temp;							
										temp.C[0] = (VRetAdd(a.C[0], b.C[0]));	
										temp.C[1] = (VRetAdd(a.C[1], b.C[1]));
										return temp;};

MATRIX2	MRetSub(MATRIX2 a, MATRIX2 b){	MATRIX2 temp;							
										temp.C[0] = (VRetSub(a.C[0], b.C[0]));	
										temp.C[1] = (VRetSub(a.C[1], b.C[1]));		
										return temp;};

MATRIX2	MRetMul(MATRIX2 a, MATRIX2 b){	MATRIX2 temp;							
										temp.C[0] = (VRetMul(a.C[0], b.C[0]));	
										temp.C[1] = (VRetMul(a.C[1], b.C[1]));	
										return temp;};

MATRIX2	MRetDiv(MATRIX2 a, MATRIX2 b){	MATRIX2 temp;							
										temp.C[0] = (VRetDiv(a.C[0], b.C[0]));	
										temp.C[1] = (VRetDiv(a.C[1], b.C[1]));	
										return temp;};

//Do MATRIX2 calulations using Scalar quantities
void	MAddSca(MATRIX2 a, SCALAR n){	VAddSca(a.C[0], n);		
										VAddSca(a.C[1], n);};

void	MSubSca(MATRIX2 a, SCALAR n){	VSubSca(a.C[0], n);		
										VSubSca(a.C[1], n);};

void	MMulSca(MATRIX2 a, SCALAR n){	VMulSca(a.C[0], n);		
										VMulSca(a.C[1], n);};

void	MDivSca(MATRIX2 a, SCALAR n){	VDivSca(a.C[0], n);		
										VDivSca(a.C[1], n);};

//The same but these will return a MATRIX2
MATRIX2	MRetAddSca(MATRIX2 a, SCALAR n){	MATRIX2 temp;						
										temp.C[0] = VRetAddSca(a.C[0], n);	
										temp.C[1] = VRetAddSca(a.C[1], n);		
										return temp;};

MATRIX2	MRetSubSca(MATRIX2 a, SCALAR n){	MATRIX2 temp;						
										temp.C[0] = VRetSubSca(a.C[0], n);	
										temp.C[1] = VRetSubSca(a.C[1], n);
										return temp;};

MATRIX2	MRetMulSca(MATRIX2 a, SCALAR n){	MATRIX2 temp;						
										temp.C[0] = VRetMulSca(a.C[0], n);	
										temp.C[1] = VRetMulSca(a.C[1], n);	
										return temp;};

MATRIX2	MRetDivSca(MATRIX2 a, SCALAR n){	MATRIX2 temp;						
										temp.C[0] = VRetDivSca(a.C[0], n);
										temp.C[1] = VRetDivSca(a.C[1], n);	
										return temp;};

//Calculations for modiying a MATRIX2 give a vector.
void	MAddVec(MATRIX2 a, VECTOR2 v){	Vadd(a.C[0], v); 
										Vadd(a.C[1], v);};

void	MSubVec(MATRIX2 a, VECTOR2 v){	Vsub(a.C[0], v); 
										Vsub(a.C[1], v);};

void	MMulVec(MATRIX2 a, VECTOR2 v){	Vmul(a.C[0], v); 
										Vmul(a.C[1], v);};

void	MDivVec(MATRIX2 a, VECTOR2 v){	Vdiv(a.C[0], v); 
										Vdiv(a.C[1], v);};

//The same but these will return a MATRIX2 instead
MATRIX2	MRetAddVec(MATRIX2 a, VECTOR2 v){	MATRIX2 temp;						
										temp.C[0] = (VRetAdd(a.C[0], v));	
										temp.C[1] = (VRetAdd(a.C[1], v));		
										return temp;};

MATRIX2	MRetSubVec(MATRIX2 a, VECTOR2 v){	MATRIX2 temp;						
										temp.C[0] = (VRetSub(a.C[0], v));	
										temp.C[1] = (VRetSub(a.C[1], v));		
										return temp;};

MATRIX2	MRetMulVec(MATRIX2 a, VECTOR2 v){	MATRIX2 temp;						
										temp.C[0] = (VRetMul(a.C[0], v));	
										temp.C[1] = (VRetMul(a.C[1], v));	
										return temp;};

MATRIX2	MRetDivVec(MATRIX2 a, VECTOR2 v){	MATRIX2 temp;						
										temp.C[0] = (VRetDiv(a.C[0], v));	
										temp.C[1] = (VRetDiv(a.C[1], v));		
										return temp;};

VECTOR2	VRetAddMat(VECTOR2 a, MATRIX2 m)
{
	VECTOR2 temp;
	temp.x = a.x + m.C[0].x + m.C[1].x;
	temp.y = a.y = m.C[0].y + m.C[1].y;
	return temp;
}


//this returns a version of the MATRIX2 that was passed in with all the column turned
// on thier side.... what fun hey....
MATRIX2	Mtranspose(MATRIX2 a){	MATRIX2 temp;				
								temp.C[0].x = a.C[0].x;		
								temp.C[0].y = a.C[1].x;		
								temp.C[1].x = a.C[0].y;	
								temp.C[1].y = a.C[1].y;		
								return temp;};

//does something or other I'm sure of it....
//SCALAR	Mdeterminant(MATRIX2 a){return( Vdot(a.C[0],(Vcross(a.C[1], a.C[2]) ) ) ); };

//MATRIX2 inverse
MATRIX2	Minverse(MATRIX2 a){MATRIX2 temp; temp.C[0] = VRetNeg(a.C[0]);	
										temp.C[1] = VRetNeg(a.C[1]);	
										return temp;};
/*
void MOrthonormalizeOrientation( MATRIX2 Orientation )
{
	VECTOR X,Y,Z;
	VSetVec(X,Orientation.C[0].x, Orientation.C[1].x, Orientation.C[2].x);
    //vector_3 X(Orientation(0,0),Orientation(1,0),Orientation(2,0));
	VSetVec(Y, Orientation.C[0].y, Orientation.C[1].y, Orientation.C[2].y);
    //vector_3 Y(Orientation(0,1),Orientation(1,1),Orientation(2,1));
    //vector_3 Z;

	Vnormalise(X);
    //X.Normalize();
	Vequ(Z, VRetnormalise(Vcross(X, Y)));
    //Z = CrossProduct(X,Y).Normalize();
	Vequ(Y, VRetnormalise(Vcross(Z, X)));
    //Y = CrossProduct(Z,X).Normalize();
	Orientation.C[0].x = X.x; 
	Orientation.C[0].y = Y.x; 
	Orientation.C[0].z = Z.x;
    //Orientation(0,0) = X(0); Orientation(0,1) = Y(0); Orientation(0,2) = Z(0);
	Orientation.C[1].x = X.y; 
	Orientation.C[1].y = Y.y; 
	Orientation.C[1].z = Z.y;
    //Orientation(1,0) = X(1); Orientation(1,1) = Y(1); Orientation(1,2) = Z(1);
	Orientation.C[2].x = X.z; 
	Orientation.C[2].y = Y.z; 
	Orientation.C[2].z = Z.z;
    //Orientation(2,0) = X(2); Orientation(2,1) = Y(2); Orientation(2,2) = Z(2);
}
*/