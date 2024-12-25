#include	"Controls.h"
#include	"Car.h"
#include	"BasicTypes.h"

/******************************************
 * HEADER
 *
 *
 *
 *
 ******************************************/
#define	COLLISION_DIAMETER	int2fp(5)

BOOL	Car_MoveCar(A_CAR car, CHAR TargetConfigIndex, CHAR SourceConfigIndex)
{	
	return TRUE;
}

void	Car_CalcMove(A_CAR car, SCALAR DeltaTime,CHAR TargetConfigIndex, CHAR SourceConfigIndex)
{	
}

BOOL	Car_CarInit(A_CAR car)
{
	return TRUE;
}

void	Car_StartRace(A_CAR car)
{
}

//All these need to be called in Dakar_game
void	Car_ComputeForces(A_CAR car, int config)
{
}

void Car_Integrate(A_CAR car, SCALAR DeltaTime,CHAR TargetConfigIndex, CHAR SourceConfigIndex)
{      
}

collision_state Car_CheckForCollisions(A_CAR car, int config)
{
    return 0;
}

void Car_ResolveCollisions(A_CAR car, int config )
{
}

void Car_CalculateVertices(A_CAR car, int config )
{
}
