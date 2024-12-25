#ifndef	_CARDEFINES_H_
#define _CARDEFINES_H_

#include "BasicTypes.h"
#include "BasicDefines.h"
#include "Matrix.h"

 //DEFINES FOR THESE FUNCTIONS

//TYPE
#define		CAR		0
#define		TRUCK	1
#define		BIKE	2

#define		EVIL_CAR	(CAR + 100)
#define		EVIL_TRUCK	(TRUCK + 100)
#define		EVIL_BIKE	(BIKE + 100)

//SPEEDS AND ACCELERATION
#define		CAR_ACCEL		2
#define		TRUCK_ACCEL		1
#define		BIKE_ACCEL		3

#define		CAR_TOPSPEED	(120 << 2)
#define		TRCUK_TOPSPEED	(100 << 2)
#define		BIKE_TOPSPEED	(140 << 2)

#define		GROUND_SLOW		1
#define		BRAKES_SLOW		5

#define TIMESTEP	(0.02)
#define G			float2fp( (9.8 * 2000) )


typedef
enum _collision_state
	{
		Penetrating,
		Colliding,
		Clear
	} collision_state ; 
collision_state	CollisionState;
typedef
struct _bounding_box
{
	VECTOR aVertices[8]; //VECTOR[4] verticeis of the collision box

}bounding_box;

typedef
struct _configuration
{
	VECTOR CMPosition; //VECTOR position of CM
	MATRIX Orientation;

	VECTOR CMVelocity; //VECTOR velocity
	VECTOR AngularVelocity; //SCALAR speed of rotation
	VECTOR AngularMomentum;

	VECTOR CMForce; //VECTOR force on the CM
	VECTOR Torque; //SCALAR turning force

	MATRIX InverseWorldInertiaTensor;

	bounding_box BoundingBox; //STRUCT verticies of bounding box

}configuration;

#endif