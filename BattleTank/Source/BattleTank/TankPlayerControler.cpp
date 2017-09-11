// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerControler.h"
#include "Engine.h"
#include "Components/PrimitiveComponent.h"
#include "Public/WorldCollision.h"
void ATankPlayerControler::BeginPlay() 
{
	Super::BeginPlay();
		
	UE_LOG(LogTemp, Warning, TEXT("%s Player controller "),*(GetControlledTank()->GetName()));
}

void ATankPlayerControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerControler::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
void ATankPlayerControler::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;//out param
	
	//get world location through crosshair line-trace
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player controller aiming towards: %s "), *HitLocation.ToString());
		//tell controlled tank to aim at this point
	}
}
bool ATankPlayerControler::GetSightRayHitLocation(FVector &HitLocation) const
{
	
	FindCrosshairPixelCoordinates();
	
	// De-project the screen position of the crosshair to a world direction
	//Line-Trace along that look direction, see what we hit(up to max range)
	
	return true;
}
//find crosshair position in pixel coordinates
void ATankPlayerControler::FindCrosshairPixelCoordinates() const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
}
