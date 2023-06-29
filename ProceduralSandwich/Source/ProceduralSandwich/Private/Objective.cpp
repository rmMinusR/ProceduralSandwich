// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective.h"

// Sets default values for this component's properties
UObjective::UObjective()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	state = EObjectiveState::NoChanges;
	completionScore.promotion = 1;
}


// Called when the game starts
void UObjective::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UObjective::MarkCompleted()
{
	if (state == EObjectiveState::NoChanges)
	{
		state = EObjectiveState::Completed;
		onCompleted.Broadcast(this);
	}
}

EObjectiveState UObjective::GetState() const
{
	return state;
}

FScore UObjective::EvalScore() const
{
	switch (state)
	{
	case EObjectiveState::NoChanges: return incompleteScore;
	case EObjectiveState::Completed: return completionScore;

	default:
		unimplemented();
		return FScore();
	}
}
