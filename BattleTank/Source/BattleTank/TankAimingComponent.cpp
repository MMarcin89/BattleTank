// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Engine.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}
void UTankAimingComponent::Initialize(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet)
{
	Turret = TurretToSet;
	Barrel = BarrelToSet;
}



void UTankAimingComponent::AimAt(FVector HitLocation)
{

	if (!ensure(Barrel)) { return; }
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
		0.f,
		0.f,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		ResponseParam,
		ActorsToIgnore,
		false
	);
	if(bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTo(AimDirection);
		MoveTurretTo(AimDirection);
		
	}

}
void UTankAimingComponent::MoveBarrelTo(FVector AimDirection)
{
	if (!ensure(Barrel)) { return; }
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotation = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotation - BarrelRotation;
	
		Barrel->Elevate(DeltaRotation.Pitch);
}
void UTankAimingComponent::MoveTurretTo(FVector AimDirection)
{
	if (!ensure(Turret)) { return; }
	auto TurretRotation = Turret->GetForwardVector().Rotation();
	auto AimAsRotation = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotation - TurretRotation;

	Turret->MoveHorizontal(DeltaRotation.Yaw);
}
void UTankAimingComponent::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;

	if (bIsReloaded)
	{
		//spawn projectile at socet location

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Socket")), Barrel->GetSocketRotation(FName("Socket")));
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}