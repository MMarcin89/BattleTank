// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"
#include "Engine.h"


void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	
}
void AMyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) 
	{
		//TODOMove towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetTargetLocation());
		//TODO Fire if ready
	}
}
ATank* AMyAIController::GetAIControlledTank() const
{
	
	return Cast<ATank>(GetPawn());
}

ATank* AMyAIController::GetPlayerTank() const
{
	 
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
ATank* AMyAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}