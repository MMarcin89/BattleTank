// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	
	UPROPERTY(BlueprintAssignable)
		FTankDelegate OnDeath;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)override;

	UFUNCTION(BlueprintPure,Category="HP")
		float GetHPPercent()const;

private:	
	UPROPERTY(EditDefaultsOnly,Category="Setup")
		int32 MaxHP = 100;
	UPROPERTY(VisibleAnywhere, Category = "HP")
		int32 CurrentHP = 10;
	int32 GetMaxHP();

	virtual void BeginPlay()override;

	
};
