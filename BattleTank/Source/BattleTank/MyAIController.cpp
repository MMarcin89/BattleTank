// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"



void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	

	UE_LOG(LogTemp, Warning, TEXT("%s AI controller "), *(GetAIControlledTank()->GetName()));
}
ATank* AMyAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


