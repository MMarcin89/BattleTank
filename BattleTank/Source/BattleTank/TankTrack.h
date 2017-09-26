// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UTankTrack();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)override;

	void ApplySidewayForce();

	UFUNCTION(BlueprintCallable, Category=Input)
		void SetThrottle(float Throttle);

	void DriveTrack();

	UPROPERTY(EditDefaultsOnly)
		float MaxDrivingForce = 45000000;
	
	virtual void BeginPlay()override;

private:
	UFUNCTION(BlueprintCallable)
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit );
	
	float CurrentThrottle = 0;
};
