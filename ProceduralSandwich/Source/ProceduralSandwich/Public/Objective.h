// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Objective.generated.h"


UENUM(BlueprintType)
enum class EObjectiveState : uint8
{
	NoChanges UMETA( DisplayName="No Action Taken" ),
	Completed UMETA( DisplayName="Completed" )
};


class UObjectiveSubsystem;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCEDURALSANDWICH_API UObjective : public UActorComponent
{
	GENERATED_BODY()

	friend class UObjectiveSubsystem;

public:	
	// Sets default values for this component's properties
	UObjective();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintGetter = "GetState", meta = (AllowPrivateAccess = "true"))
	EObjectiveState state;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", ClampMin = "0.0"))
	float completionValue;

	DECLARE_EVENT_OneParam(UObjective, FObjectiveCallback, UObjective*)
	FObjectiveCallback onCompleted;

public:
	UFUNCTION(BlueprintCallable)
	void MarkCompleted();

	UFUNCTION(BlueprintPure)
	EObjectiveState GetState();
};
