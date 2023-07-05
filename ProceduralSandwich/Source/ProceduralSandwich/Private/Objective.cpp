// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective.h"

// Sets default values for this component's properties
UObjective::UObjective()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	state = EObjectiveState::NoInteraction;
}


// Called when the game starts
void UObjective::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

EObjectiveState UObjective::GetState() const
{
	return state;
}

FScore UObjective::EvalScoreFor_Implementation(APlayerState* who) const
{
	unimplemented();
	return FScore();
}
