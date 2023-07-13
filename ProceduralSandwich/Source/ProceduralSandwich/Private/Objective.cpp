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

UObjective::~UObjective()
{
}

TArray<UObjective*> UObjective::GetLiveObjectives()
{
	return UObjective::INSTANCES;
}

TArray<UObjective*> UObjective::INSTANCES;

void UObjective::BeginPlay()
{
	Super::BeginPlay();

	UObjective::INSTANCES.Add(this);
}

void UObjective::BeginDestroy()
{
	Super::BeginDestroy();

	UObjective::INSTANCES.Remove(this);
}

EObjectiveState UObjective::GetState() const
{
	return state;
}

UObjectiveViewRepresentation* UObjective::GetView()
{
	UObjectiveViewRepresentation* out = NewObject<UObjectiveViewRepresentation>();

	//Write view data
	//Note that these changes will reflect in copiers, but they should make a value copy instead if they don't want that happening
	out->dataSource = const_cast<UObjective*>(this);
	out->displayName = this->displayName;
	out->displayState = this->GetState();

	return out;
}

FScore UObjective::EvalScoreFor_Implementation(APlayerState* who) const
{
	unimplemented();
	return FScore();
}

void UObjective::AssumeDefaultIfNoInteraction_Implementation()
{
	unimplemented();
}

bool UObjective::ShouldShowViewFor_Implementation(APlayerState* who) const
{
	return true;
}
