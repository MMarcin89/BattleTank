// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerControler.generated.h"


class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerControler : public APlayerController
{
	GENERATED_BODY()


protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent*AimComponentRef);

private:
	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5f;
	
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.333333f;
	
	UPROPERTY(EditAnywhere)
		float TankRange = 100000;
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float) override;

	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector&HitLocation)const;

	bool bGetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;
	
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection)const;

};
