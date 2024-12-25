#include "Matrix.h"
/* * * * *
 * OK this is a matrix type, It'll help with traslations and defining rigid
 * body physics.
 *
 * I'm going to try to do as much as as possible in inline functions.....
 *
 * Oh the matrix is in [column][row] format which is slightly different than usual.
 * * * * */


//checks equality between maticies
BOOL 	MIsEqual(MATRIX a, MATRIX b){ return(VIsEqual(a.C[0],b.C[0]) &&  VIsEqual(a.C[1],b.C[1]) && VIsEqual(a.C[2],b.C[2]));};

//Check if One matrix is not equal to another
BOOL	MIsNotEqual(MATRIX a, MATRIX b){ return( !MIsEqual(a,b) );};

//Make one matrix equal to another
void	Mequ(MATRIX a, MATRIX b){	Vequ(a.C[0], b.C[0]); 
									Vequ(a.C[1], b.C[1]); 
									Vequ(a.C[2], b.C[2]);};

//add one matrix to another
void	Madd(MATRIX a, MATRIX b){	Vadd(a.C[0], b.C[0]); 
									Vadd(a.C[1], b.C[1]); 
									Vadd(a.C[2], b.C[2]);};

//subtract one matrix from another
void	Msub(MATRIX a, MATRIX b){	Vsub(a.C[0], b.C[0]); 
									Vsub(a.C[1], b.C[1]); 
									Vsub(a.C[2], b.C[2]);};


//multiply one matrix by another
void	Mmul(MATRIX a, MATRIX b)
{
	/*
	MATRIX temp = (*this);

	C[0] = temp * m.C[0];

	C[1] = temp * m.C[1];

	C[2] = temp * m.C[2];
	*/

	Vequ(a.C[0],(VRetMulVec(b.C[0], a)));
	Vequ(a.C[1],(VRetMulVec(b.C[1], a)));
	Vequ(a.C[2],(VRetMulVec(b.C[2], a)));
};


//divide one matrix by another
void	Mdiv(MATRIX a, MATRIX b){	Vdiv(a.C[0], b.C[0]); 
									Vdiv(a.C[1], b.C[1]); 
									Vdiv(a.C[2], b.C[2]);};

//Same as the above functions but these will return a MATRIX
MATRIX	MRetAdd(MATRIX a, MATRIX b){	MATRIX temp;							
										temp.C[0] = (VRetAdd(a.C[0], b.C[0]));	
										temp.C[1] = (VRetAdd(a.C[1], b.C[1]));	
										temp.C[2] = (VRetAdd(a.C[2], b.C[2]));	
										return temp;};

MATRIX	MRetSub(MATRIX a, MATRIX b){	MATRIX temp;							
										temp.C[0] = (VRetSub(a.C[0], b.C[0]));	
										temp.C[1] = (VRetSub(a.C[1], b.C[1]));	
										temp.C[2] = (VRetSub(a.C[2], b.C[2]));	
										return temp;};

MATRIX	MRetMul(MATRIX a, MATRIX b){	MATRIX temp;							
										Vequ(temp.C[0],(VRetMulVec(b.C[0], a)));
										Vequ(temp.C[1],(VRetMulVec(b.C[1], a)));
										Vequ(temp.C[2],(VRetMulVec(b.C[2], a)));
										return temp;};

MATRIX	MRetDiv(MATRIX a, MATRIX b){	MATRIX temp;							
										temp.C[0] = (VRetDiv(a.C[0], b.C[0]));	
										temp.C[1] = (VRetDiv(a.C[1], b.C[1]));	
										temp.C[2] = (VRetDiv(a.C[2], b.C[2]));	
										return temp;};

//Do matrix calulations using Scalar quantities
void	MAddSca(MATRIX a, SCALAR n){	VAddSca(a.C[0], n);		
										VAddSca(a.C[1], n);		
										VAddSca(a.C[2], n);};

void	MSubSca(MATRIX a, SCALAR n){	VSubSca(a.C[0], n);		
										VSubSca(a.C[1], n);		
										VSubSca(a.C[2], n);};

void	MMulSca(MATRIX a, SCALAR n){	VMulSca(a.C[0], n);		
										VMulSca(a.C[1], n);		
										VMulSca(a.C[2], n);};

void	MDivSca(MATRIX a, SCALAR n){	VDivSca(a.C[0], n);		
										VDivSca(a.C[1], n);		
										VDivSca(a.C[2], n);};

//The same but these will return a MATRIX
MATRIX	MRetAddSca(MATRIX a, SCALAR n){	MATRIX temp;						
										temp.C[0] = VRetAddSca(a.C[0], n);	
										temp.C[1] = VRetAddSca(a.C[1], n);	
										temp.C[2] = VRetAddSca(a.C[2], n);	
										return temp;};

MATRIX	MRetSubSca(MATRIX a, SCALAR n){	MATRIX temp;						
										temp.C[0] = VRetSubSca(a.C[0], n);	
										temp.C[1] = VRetSubSca(a.C[1], n);
										temp.C[2] = VRetSubSca(a.C[2], n);
										return temp;};

MATRIX	MRetMulSca(MATRIX a, SCALAR n){	MATRIX temp;						
										temp.C[0] = VRetMulSca(a.C[0], n);	
										temp.C[1] = VRetMulSca(a.C[1], n);
										temp.C[2] = VRetMulSca(a.C[2], n);	
										return temp;};

MATRIX	MRetDivSca(MATRIX a, SCALAR n){	MATRIX temp;						
										temp.C[0] = VRetDivSca(a.C[0], n);
										temp.C[1] = VRetDivSca(a.C[1], n);	
										temp.C[2] = VRetDivSca(a.C[2], n);	
										return temp;};

//Calculations for modiying a matrix give a vector.
void	MAddVec(MATRIX a, VECTOR v){	Vadd(a.C[0], v); 
										Vadd(a.C[1], v); 
										Vadd(a.C[2], v);};

void	MSubVec(MATRIX a, VECTOR v){	Vsub(a.C[0], v); 
										Vsub(a.C[1], v); 
										Vsub(a.C[2], v);};

void	MMulVec(MATRIX a, VECTOR v){	Vmul(a.C[0], v); 
										Vmul(a.C[1], v); 
										Vmul(a.C[2], v);};

void	MDivVec(MATRIX a, VECTOR v){	Vdiv(a.C[0], v); 
										Vdiv(a.C[1], v); 
										Vdiv(a.C[2], v);};

//The same but these will return a Matrix instead
MATRIX	MRetAddVec(MATRIX a, VECTOR v){	MATRIX temp;						
										temp.C[0] = (VRetAdd(a.C[0], v));	
										temp.C[1] = (VRetAdd(a.C[1], v));	
										temp.C[2] = (VRetAdd(a.C[2], v));	
										return temp;};

MATRIX	MRetSubVec(MATRIX a, VECTOR v){	MATRIX temp;						
										temp.C[0] = (VRetSub(a.C[0], v));	
										temp.C[1] = (VRetSub(a.C[1], v));	
										temp.C[2] = (VRetSub(a.C[2], v));	
										return temp;};

MATRIX	MRetMulVec(MATRIX a, VECTOR v){	MATRIX temp;						
										temp.C[0] = (VRetMul(a.C[0], v));	
										temp.C[1] = (VRetMul(a.C[1], v));	
										temp.C[2] = (VRetMul(a.C[2], v));	
										return temp;};

MATRIX	MRetDivVec(MATRIX a, VECTOR v){	MATRIX temp;						
										temp.C[0] = (VRetDiv(a.C[0], v));	
										temp.C[1] = (VRetDiv(a.C[1], v));	
										temp.C[2] = (VRetDiv(a.C[2], v));	
										return temp;};

VECTOR	VRetAddMat(VECTOR a, MATRIX m)
{
	VECTOR temp;
	temp.x = a.x + m.C[0].x + m.C[1].x + m.C[2].x;
	temp.y = a.y = m.C[0].y + m.C[1].y + m.C[2].y;
	temp.z = a.z = m.C[0].z + m.C[1].z + m.C[2].z;
	return temp;
}


//this returns a version of the Matrix that was passed in with all the column turned
// on thier side.... what fun hey....
MATRIX	Mtranspose(MATRIX a){	MATRIX temp;				
								temp.C[0].x = a.C[0].x;		
								temp.C[0].y = a.C[1].x;		
								temp.C[0].z = a.C[2].x;		
								temp.C[1].x = a.C[0].y;	
								temp.C[1].y = a.C[1].y;		
								temp.C[1].z = a.C[2].y;		
								temp.C[2].x = a.C[0].z;		
								temp.C[2].y = a.C[1].z;		
								temp.C[2].z = a.C[2].z;		
								return temp;};

//does something or other I'm sure of it....
SCALAR	Mdeterminant(MATRIX a){return( Vdot(a.C[0],(Vcross(a.C[1], a.C[2]) ) ) ); };

//matrix inverse
MATRIX	Minverse(MATRIX a){MATRIX temp; temp.C[0] = VRetNeg(a.C[0]);	
										temp.C[1] = VRetNeg(a.C[1]);	
										temp.C[2] = VRetNeg(a.C[2]);	
										return temp;};

void MOrthonormalizeOrientation( MATRIX Orientation )
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

void	MCreateSkewSymmetricMatrix(MATRIX m, VECTOR v)
{
	m.C[0].x = 0;				m.C[0].y = -v.z;			m.C[0].z = v.y;
    m.C[1].x = v.z;				m.C[1].y =  0;				m.C[1].z = -v.x;
    m.C[2].x = -v.y;			m.C[2].y =  v.x;			m.C[2].z = 0;
}

VECTOR	VRetMulVec(VECTOR v, MATRIX m)
{
	VECTOR temp;

	temp.x = fpMul(v.x,m.C[0].x) + fpMul(v.y, m.C[0].y) + fpMul(v.z, m.C[0].z); 
	temp.y = fpMul(v.x,m.C[1].x) + fpMul(v.y, m.C[1].y) + fpMul(v.z, m.C[1].z); 
	temp.z = fpMul(v.x,m.C[2].x) + fpMul(v.y, m.C[2].y) + fpMul(v.z, m.C[2].z);
	
	return temp;
}


/* * * * * * * 
 * This is the place for functions from BASIS.H
 * I'm only using this because I hope to change the code to 
 * assembly at some point....
 * * * * * * */
VECTOR	x(MATRIX a){return a.C[0]; };
VECTOR	y(MATRIX a){return a.C[1]; };
VECTOR	z(MATRIX a){return a.C[2]; };

void MRotateAroundX( MATRIX a,SCALAR n )
{
	if( 0 != n )//don’t rotate by 0
	{
		VECTOR b1;
		VECTOR b2;

		Vequ(b1,VRetAdd( (VRetMulSca(y(a),fpCos(n))), (VRetMulSca(z(a),fpSin(n)))));

		 //= -this->Y()*sin(a) + this->Z()*cos(a);

		Vequ(b2, VRetAdd( (VRetMulSca(y(a),fpCos(n))) , VRetNeg(VRetMulSca(z(a),fpSin(n)))));
		//set basis

		Vequ(a.C[1],b1);

		Vequ(a.C[2],b2);

		//x is unchanged
	}
}

void MRotateAroundY(MATRIX a, SCALAR n )
{
	if( 0 != n )//don’t rotate by 0
	{
		VECTOR b0;
		VECTOR b2;		//this->Z()*cos(a) + this->X()*sin(a); //rotate z

		Vequ(b2,VRetAdd( (VRetMulSca(z(a),fpCos(n))), (VRetMulSca(x(a),fpSin(n)))));

		 //= -this->Z()*sin(a) + this->X()*cos(a); //rotate x
		Vequ(b0, VRetAdd( (VRetMulSca(z(a),fpCos(n))) , VRetNeg(VRetMulSca(x(a),fpSin(n)))));


		//set basis

		Vequ(a.C[2],b2);

		Vequ(a.C[0],b0);

		//y is unchanged
	}
}

void MRotateAroundZ(MATRIX a, SCALAR n )
{
	if( 0 != n )//don’t rotate by 0
	{
		//don’t over-write basis before calculation is done
		VECTOR b1;
		VECTOR b0; //= this->X()*cos(a) + this->Y()*sin(a); //rotate x
		
		Vequ(b0,VRetAdd( (VRetMulSca(x(a),fpCos(n))), (VRetMulSca(y(a),fpSin(n)))));

		// = -this->X()*sin(a) + this->Y()*cos(a); //rotate y
		Vequ(b1, VRetAdd( (VRetMulSca(x(a),fpCos(n))) , VRetNeg(VRetMulSca(y(a),fpSin(n)))));
		//set basis

		Vequ(a.C[0],b0);
		//this->M[0] = b0;

		Vequ(a.C[1],b1);
		//this->M[1] = b1;

		//z is unchanged
	}
}






VECTOR MtransformVectorToLocal( MATRIX a, VECTOR v ) {	VECTOR temp;				
														temp.x = Vdot(a.C[0], v);	
														temp.y = Vdot(a.C[1], v);	
														temp.z = Vdot(a.C[2], v);	
														return temp;				
													};

VPOINT MtransformVectorToParent(MATRIX a, VECTOR v){	VECTOR temp;																							
													Vequ(temp, ( VRetAdd(VRetAdd(VRetMul(a.C[0], v) , VRetMul(a.C[1] , v)) , VRetMul(a.C[2], v))));	
													return (VPOINT)temp;};


VPOINT	MTransformPointToLocal(MATRIX cf, VPOINT pos,  VPOINT p)
{
	VECTOR a;
	Vequ(a,MtransformVectorToLocal(cf, VRetSub(p,pos)));
	return (VPOINT)a;
}

VPOINT   MTransformPointToParent(MATRIX cf,VPOINT pos, VPOINT p)
{
	VECTOR a;
	Vequ(a, MtransformVectorToParent(cf, p));
	Vadd(a, pos);
	return a;
}

void	MTranslate(MATRIX cf,VPOINT pos, VECTOR v)
{
	Vadd(pos, v);
}