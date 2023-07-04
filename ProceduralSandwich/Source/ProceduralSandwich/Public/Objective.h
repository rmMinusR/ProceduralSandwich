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


class APlayerState;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCEDURALSANDWICH_API UObjective : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjective();

	UFUNCTION(BlueprintCallable)
	static TArray<UObjective*> GetLiveObjectives();
private:
	static TArray<UObjective*> INSTANCES; // Fast lookup
protected:
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

	UPROPERTY(EditAnywhere, BlueprintGetter = "GetState", meta = (AllowPrivateAccess = "true"))
	EObjectiveState state;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FScore completionScore;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FScore incompleteScore;

	/** Allow "stealing" objectives */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bIsContestable;

	/** Leave null to allow anyone to claim */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	APlayerState* owner;

	/** Who takes the credit for completing (or blame for failing) this objective */
	UPROPERTY(VisibleInstanceOnly, BlueprintGetter = "GetCreditor", meta = (AllowPrivateAccess = "true"))
	APlayerState* creditor;

public:
	DECLARE_EVENT_OneParam(UObjective, FObjectiveCallback, UObjective*)
	FObjectiveCallback onCompleted;

	UFUNCTION(BlueprintCallable)
	void TryMarkCompleted(APlayerState* who);

	UFUNCTION(BlueprintPure)
	EObjectiveState GetState() const;

	UFUNCTION(BlueprintPure)
	APlayerState* GetCreditor() const;

	UFUNCTION(BlueprintPure)
	FScore EvalScoreFor(APlayerState* who) const;
};
