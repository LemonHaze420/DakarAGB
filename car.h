#ifndef _CAR_H_
#define _CAR_H_
#include "CarDefines.h"
#include "BasicTypes.h"
#include "Matrix.h"
#include "extern.h"
//#include "Matrix2.h"

/* * * * * * *
 * This struct holds all the information the graphics engine needs to know to draw the car.
 * I've tried to use the smallest variables I can.
 * Hopefully an assembler prog could go through this struct quickly enough.
 * * * * * * */
typedef
struct _CAR
{
	//RIGID_BODY theCar;	//This is a basic definition of the car.
						//i.e. how it will move, where it is... that sort of stuff.
	CHAR carType;		//This is not a car... or to be less philisophical, it may be a truck
						//or a bike, or an aubergine.

	SCALAR Width, Length, Height;
	SCALAR OneOverMass, OneOverCMMomentOfInertia;
	SCALAR CoefficientOfRestitution;
	MATRIX InverseBodyInertiaTensor;

	enum { NumberOfConfigurations = 2 };
	configuration aConfigurations[NumberOfConfigurations]; //STRUCT[2] configs

}A_CAR;

//a collision struct for holding info on collisions this turn ready to be calculated
#define MAX_NUM_COLLISIONS	6
typedef
struct _collisionInfo
{
	INT					CollidingBodyIndex;
	INT					CollidingCornerIndex;
	VPOINT				collidingPoint;
	collision_state		state;
}
collisionInfo;

struct	collisions
{
	UCHAR	numberOfCollisions;
	collisionInfo	Info[MAX_NUM_COLLISIONS];
}
TheCollisions;
//this is the main function for the car.
//I think to keep speed up its all going to have to be inlined so it's gonna look
//horrible but if it works, it works.
//At the moment the passed in parameters are commented out.
//this is because I don't quite know how they are going to work.
BOOL	Car_MoveCar(A_CAR car,CHAR TargetConfigIndex, CHAR SourceConfigIndex);

//This is the Init fuction for a car, you pass in the car type and the fuction will do the rest
BOOL	Car_CarInit(A_CAR car);

//this function sets up a car to start a race
void	Car_StartRace(A_CAR car);

void Car_ComputeForces(A_CAR car, int config);
void Car_Integrate(A_CAR car, SCALAR DeltaTime,CHAR TargetConfigIndex, CHAR SourceConfigIndex);
collision_state Car_CheckForCollisions(A_CAR car, int config);
void Car_ResolveCollisions(A_CAR car, int config );
void Car_CalculateVertices(A_CAR car, int config );
void Car_CalcMove(A_CAR car, SCALAR DeltaTime,CHAR TargetConfigIndex, CHAR SourceConfigIndex);

#endif