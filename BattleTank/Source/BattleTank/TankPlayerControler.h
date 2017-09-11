// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerControler.generated.h"


UCLASS()
class BATTLETANK_API ATankPlayerControler : public APlayerController
{
	GENERATED_BODY()
	
	
private:
	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.333333f;
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;
	virtual void Tick(float) override;
	
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector&HitLocation)const;
	void FindCrosshairPixelCoordinates() const;
};
