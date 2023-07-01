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
	bIsContestable = false;
	owner = nullptr;
	creditor = nullptr;
}


// Called when the game starts
void UObjective::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UObjective::TryMarkCompleted(APlayerState* who)
{
	if ((!owner || owner == who) && (!creditor || bIsContestable))
	{
		state = EObjectiveState::Completed;
		onCompleted.Broadcast(this);
		creditor = who;
	}
}

EObjectiveState UObjective::GetState() const
{
	return state;
}

APlayerState* UObjective::GetCreditor() const
{
	return creditor;
}

FScore UObjective::EvalScoreFor(APlayerState* who) const
{
	if (who == creditor) // You took credit (or blame)
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
	else if (who == owner) // You were supposed to interact but didn't, or it was stolen. Always count as incomplete.
	{
		return incompleteScore;
	}
	else // You didn't interact, but didn't have to. No change.
	{
		return FScore();
	}
}
