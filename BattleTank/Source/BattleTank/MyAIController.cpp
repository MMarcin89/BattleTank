// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"
#include "Engine.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "GameFramework/Pawn.h"


void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	
}
void AMyAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossesedTank = Cast<ATank>(InPawn);
		if (!ensure(PossesedTank)) { return; }
		//subscribe our local method
		PossesedTank->OnDeath.AddUniqueDynamic(this, &AMyAIController::OnTankDeath);
	}

}
void AMyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AItank = GetPawn();
	auto AimingComponent = AItank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	if (ensure(PlayerTank))
	{
		//Move towards player
		MoveToActor(PlayerTank, StopDistance);
		AimingComponent->AimAt(PlayerTank->GetTargetLocation());
		if (AimingComponent->GetFireStatus() == EFireStatus::Locked)
		{
			AimingComponent->Fire();
		}
	}
}
void AMyAIController::OnTankDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy(); //or Destroy()?
}