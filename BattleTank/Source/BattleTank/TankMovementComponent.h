// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible for driving tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintCallable,Category=Input)
		void IntendMoveForward(float StickThrow);
	
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendRotateClockwise(float StickThrow);

	UFUNCTION(BlueprintCallable, Category=Setup)
		void Initialize(UTankTrack*LeftTrackToSet, UTankTrack*RightTrackToSet);

private:
	UTankTrack* LeftTrack = nullptr;

	UTankTrack* RightTrack = nullptr;
	
	
};