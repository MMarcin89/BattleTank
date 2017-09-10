// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"
#include "Engine.h"


void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("%s detected by %s AI controller "), *(GetPlayerTank()->GetName()), *(GetAIControlledTank()->GetName()));
}
ATank* AMyAIController::GetAIControlledTank() const
{
	
	return Cast<ATank>(GetPawn());
}

ATank* AMyAIController::GetPlayerTank() const
{
	 
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}