// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGrabber();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	float PlayerReach;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	
	// Ray-cast and grab what's in reach
	void Grab();

	// Release grabbed object
	void Release();

	// Helper function to find and setup the input component
	void SetupInputComponent();

	// Helper function to find the physics component
	void FindPhysicsComponent();

	// Find first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;

	FTwoVectors GetLineTracePoints() const;
};
