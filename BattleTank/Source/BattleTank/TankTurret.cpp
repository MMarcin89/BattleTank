// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine.h"

void UTankTurret::MoveHorizontal(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto HorizontalChange = RelativeSpeed* MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto NewHorizontalPos = RelativeRotation.Yaw + HorizontalChange;
	SetRelativeRotation(FRotator(0, NewHorizontalPos, 0));
}
