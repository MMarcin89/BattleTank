// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"




// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	}



float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	//int32 Damage = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp<int32>(DamageAmount, 0, CurrentHP);
	CurrentHP -= DamageToApply;
	if (CurrentHP == 0)
	{
		Destroy();
	}


	UE_LOG(LogTemp,Warning,TEXT("DamageAmount: %f DamageToApply: %i"), DamageAmount, DamageToApply)

	return DamageToApply;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	}


