// Fill out your copyright notice in the Description page of Project Settings.


#include "FailableObjective.h"


UFailableObjective::UFailableObjective()
{
	failScore.annoyance = 1;
	owner = nullptr;
}

void UFailableObjective::TryMarkFailed(APlayerState* who)
{
	if (!owner || owner == who)
	{
		state = EObjectiveState::Failed;
		onFailed.Broadcast(this);
	}
}

FScore UFailableObjective::EvalScoreFor_Implementation(APlayerState* who) const
{
	if (!owner || who == owner) // You failed
	{
		switch (state)
		{
		case EObjectiveState::Completed: return FScore();
		case EObjectiveState::Failed: return failScore;

		case EObjectiveState::NoInteraction: return FScore();
			
		default:
			unimplemented();
			return FScore();
		}
	}
	else // Not your problem. No change.
	{
		return FScore();
	}
}

void UFailableObjective::AssumeDefaultIfNoInteraction_Implementation()
{
	if (state == EObjectiveState::NoInteraction) state = EObjectiveState::Completed;
}

bool UFailableObjective::ShouldShowViewFor_Implementation(APlayerState* who) const
{
	return !owner || owner == who;
}
