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
