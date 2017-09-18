// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed* MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto NewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(NewElevation, MinElevation, MaxElevation);
	
		SetRelativeRotation(FRotator(Elevation, 0, 0));
	
}
