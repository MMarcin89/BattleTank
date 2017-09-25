// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerControler.h"
#include "TankAimingComponent.h"
#include "Engine.h"
#include "Engine/EngineTypes.h"
#include "Components/PrimitiveComponent.h"
#include "Public/WorldCollision.h"

void ATankPlayerControler::BeginPlay() 
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimingComponent))
	{
		FoundAimingComponent(AimingComponent);
	}
}

void ATankPlayerControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerControler::AimTowardsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation;//out param
	
	//get world location through crosshair line-trace
	if (GetSightRayHitLocation(HitLocation))
	{
		//tell controlled tank to aim at this point
		AimingComponent->AimAt(HitLocation);
	}
}
bool ATankPlayerControler::GetSightRayHitLocation(FVector &HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
		FHitResult Hit ;
		auto StartLocation=PlayerCameraManager->GetCameraLocation();
		auto EndLocation = StartLocation + LookDirection*TankRange;
		FCollisionResponseParams response;

		GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility, TraceParameters, response);
		HitLocation = Hit.ImpactPoint;
	}
	
	// De-project the screen position of the crosshair to a world direction
	//Line-Trace along that look direction, see what we hit(up to max range)
	
	return true;
}
bool ATankPlayerControler::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection)const
{
	FVector CameraLocation(0);
	
 return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, LookDirection);	 
}

