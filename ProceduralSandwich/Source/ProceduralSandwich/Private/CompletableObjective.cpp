// Fill out your copyright notice in the Description page of Project Settings.


#include "CompletableObjective.h"

UCompletableObjective::UCompletableObjective()
{
	completionScore.promotion = 1;
	owner = nullptr;
}

void UCompletableObjective::TryMarkCompleted(APlayerState* who)
{
	if (!owner || owner == who)
	{
		state = EObjectiveState::Completed;
		onCompleted.Broadcast(this);
	}
}

FScore UCompletableObjective::EvalScoreFor_Implementation(APlayerState* who) const
{
	if (!owner || who == owner) // You took credit
	{
		switch (state)
		{
		case EObjectiveState::Failed: return incompleteScore;
		case EObjectiveState::Completed: return completionScore;

		case EObjectiveState::NoInteraction: return FScore();
			
		default:
			unimplemented();
			return FScore();
		}
	}
	else // You didn't interact, but didn't have to. No change.
	{
		return FScore();
	}
}

void UCompletableObjective::AssumeDefaultIfNoInteraction_Implementation()
{
	if (state == EObjectiveState::NoInteraction) state = EObjectiveState::Failed;
}

bool UCompletableObjective::ShouldShowViewFor_Implementation(APlayerState* who) const
{
	return !owner || owner == who;
}
