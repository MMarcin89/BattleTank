// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack*LeftTrackToSet, UTankTrack*RightTrackToSet)
{
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float StickThrow)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(StickThrow);
	RightTrack->SetThrottle(StickThrow);
}


void UTankMovementComponent::IntendRotateClockwise(float StickThrow)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(StickThrow);
	RightTrack->SetThrottle(-StickThrow);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIMoveForwardIntention = MoveVelocity.GetSafeNormal();

	float ForwardThrow = FVector::DotProduct(TankForward, AIMoveForwardIntention);
	auto  RightThrow= FVector::CrossProduct(TankForward, AIMoveForwardIntention).Z;
	IntendRotateClockwise(RightThrow);
	IntendMoveForward(ForwardThrow);
	
	//UE_LOG(LogTemp, Warning, TEXT("%s moving in direction %s"));
}