// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective.h"
#include "CompletableObjective.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class PROCEDURALSANDWICH_API UCompletableObjective : public UObjective
{
	GENERATED_BODY()

protected:
	/**
	 * If null, anyone can complete, and reward is given to everyone
	 */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	APlayerState* owner;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FScore completionScore;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FScore incompleteScore;
	
public:
	UCompletableObjective();

	DECLARE_EVENT_OneParam(UCompletableObjective, FObjectiveCallback, UCompletableObjective*)
	FObjectiveCallback onCompleted;

	UFUNCTION(BlueprintCallable)
	void TryMarkCompleted(APlayerState* who);

protected:
	virtual FScore EvalScoreFor_Implementation(APlayerState* who) const override;
	virtual void AssumeDefaultIfNoInteraction_Implementation() override;
	virtual bool ShouldShowViewFor_Implementation(APlayerState* who) const override;
};
