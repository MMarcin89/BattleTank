// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerControler.h"
void ATankPlayerControler::BeginPlay() 
{
	Super::BeginPlay();
		
	UE_LOG(LogTemp, Warning, TEXT("%s Player controller "),*(GetControlledTank()->GetName()));
}
ATank* ATankPlayerControler::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


