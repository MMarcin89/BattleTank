// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;

//Enum for aiming state
UENUM()
enum class EFireStatus :uint8
{
	Locked,
	Reloading,
	Aiming
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);
	
	UFUNCTION(BlueprintCallable)
		void Fire();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "FireStatus")
		EFireStatus ActualStatus = EFireStatus::Locked;
	
private:	
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	
	void MoveBarrelTo(FVector AimDirection);
	void MoveTurretTo(FVector AimDirection);
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 5000.f;

	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTime = 2;
	
	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

};
