// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Score.h"
#include "Objective.generated.h"


UENUM(BlueprintType)
enum class EObjectiveState : uint8
{
	NoChanges UMETA( DisplayName="No Action Taken" ),
	Completed UMETA( DisplayName="Completed" )
};


class APawn;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCEDURALSANDWICH_API UObjective : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjective();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintGetter = "GetState", meta = (AllowPrivateAccess = "true"))
	EObjectiveState state;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FScore completionScore;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FScore incompleteScore;

public:
	DECLARE_EVENT_OneParam(UObjective, FObjectiveCallback, UObjective*)
	FObjectiveCallback onCompleted;

	UFUNCTION(BlueprintCallable)
	void MarkCompleted(APawn* whoCompleted);

	UFUNCTION(BlueprintPure)
	EObjectiveState GetState() const;

	UFUNCTION(BlueprintPure)
	FScore EvalScore() const;
};
