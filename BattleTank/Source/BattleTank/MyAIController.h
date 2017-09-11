// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank* GetAIControlledTank() const;
	ATank* GetPlayerTank() const;
	virtual void BeginPlay() override;

	
	
	
};
