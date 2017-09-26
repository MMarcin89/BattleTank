// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API AMyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly ,Category="Setup")
		float StopDistance = 10000;
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime)override;
	
	
	
};
