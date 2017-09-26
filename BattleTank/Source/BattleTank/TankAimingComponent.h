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
	Aiming,
	OutOfAmmo
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	
	EFireStatus GetFireStatus()const;

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);
	
	UFUNCTION(BlueprintCallable)
		void Fire();
	
	void AimAt(FVector HitLocation);
	FVector AimDirection;
	
	UFUNCTION(BlueprintCallable, Category = "FireStatus")
		int GetBulletsLeft()const;
protected:
	
	UPROPERTY(BlueprintReadOnly, Category = "FireStatus")
		EFireStatus ActualStatus = EFireStatus::Reloading;

	
		
private:	
	
	virtual void BeginPlay()override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)override;
	
	bool bIsTurretMoving();

	void MoveBarrelTo(FVector AimDirection);

	void MoveTurretTo(FVector AimDirection);
	

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 5000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTime = 2;
	
	
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	
	int BulletsLeft = 3;

	double LastFireTime = 0;
};
