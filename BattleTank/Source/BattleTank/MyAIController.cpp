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
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* AItank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		//TODOMove towards player
		AItank->AimAt(PlayerTank->GetTargetLocation());
		//TODO Fire if ready
		AItank->Fire();
	}
}
