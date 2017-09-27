// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UStaticMeshComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;
class URadialForceComponent;

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	void LaunchProjectile(float Speed);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UProjectileMovementComponent* ProjectileComponent = nullptr;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* CollisionMesh = nullptr;
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* LaunchBlast = nullptr;
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* ImpactBlast = nullptr;
	UPROPERTY(VisibleAnywhere)
		URadialForceComponent* ExplosionForce = nullptr;
	UPROPERTY(EditDefaultsOnly,Category="Setup")
		float DestroyDelay = 1;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float BaseDamage = 20;

	void OnTimerExpire();

	UFUNCTION(BlueprintCallable)
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
