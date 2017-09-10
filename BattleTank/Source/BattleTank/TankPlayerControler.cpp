// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerControler.h"
void ATankPlayerControler::BeginPlay() 
{
	Super::BeginPlay();
		
	UE_LOG(LogTemp, Warning, TEXT("%s Player controller "),*(GetControlledTank()->GetName()));
}

void ATankPlayerControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

ATank* ATankPlayerControler::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
void ATankPlayerControler::AimTowardsCrosshair()
{
	if (GetControlledTank()) { return; }
	//get world location through crosshair line-trace
	//if it hits the landscape
	//tell controlled tank to aim at this point
}