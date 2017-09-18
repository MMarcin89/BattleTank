// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Engine.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}
void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
}
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}




void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{

	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Socket"));
	FCollisionResponseParams ResponseParam;
	TArray<AActor*> ActorsToIgnore;
	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		10.f,
		0.f,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		ResponseParam,
		ActorsToIgnore,
		true
	);
	if(bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTo(AimDirection);
		MoveTurretTo(AimDirection);
		
	}
	else
	{
		
	}
}
void UTankAimingComponent::MoveBarrelTo(FVector AimDirection)
{
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotation = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotation - BarrelRotation;
	
		Barrel->Elevate(DeltaRotation.Pitch);
}
void UTankAimingComponent::MoveTurretTo(FVector AimDirection)
{
	auto TurretRotation = Turret->GetForwardVector().Rotation();
	auto AimAsRotation = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotation - TurretRotation;

	Turret->MoveHorizontal(DeltaRotation.Yaw);
}