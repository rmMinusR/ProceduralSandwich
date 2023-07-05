// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective.h"
#include "FailableObjective.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class PROCEDURALSANDWICH_API UFailableObjective : public UObjective
{
	GENERATED_BODY()

protected:
	/**
	 * If null, anyone can fail, and penalty applies to everyone
	 */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	APlayerState* owner;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FScore failScore;
	
public:
	UFailableObjective();

	DECLARE_EVENT_OneParam(UFailableObjective, FObjectiveCallback, UFailableObjective*)
	FObjectiveCallback onFailed;

	UFUNCTION(BlueprintCallable)
	void TryMarkFailed(APlayerState* who);

protected:
	virtual FScore EvalScoreFor_Implementation(APlayerState* who) const override;
};
