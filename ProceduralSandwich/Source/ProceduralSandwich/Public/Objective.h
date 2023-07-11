// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Score.h"
#include "ObjectiveViewRepresentation.h"
#include "Objective.generated.h"


class APlayerState;


UCLASS( Abstract, Blueprintable, ClassGroup=(Custom) )
class PROCEDURALSANDWICH_API UObjective : public UActorComponent
{
	GENERATED_BODY()

public:	
	UObjective();
	virtual ~UObjective();

	UFUNCTION(BlueprintCallable)
	static TArray<UObjective*> GetLiveObjectives();
private:
	static TArray<UObjective*> INSTANCES; // Fast lookup
protected:
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

	UPROPERTY(EditAnywhere, BlueprintGetter = "GetState", meta = (AllowPrivateAccess = "true"))
	EObjectiveState state;

public:
	UFUNCTION(BlueprintPure)
	EObjectiveState GetState() const;


public:
	UFUNCTION(BlueprintPure)
	virtual UObjectiveViewRepresentation* GetView();

	UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	bool ShouldShowViewFor(APlayerState* who) const;
protected:
	virtual bool ShouldShowViewFor_Implementation(APlayerState* who) const; // = 0
	

public:
	UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	FScore EvalScoreFor(APlayerState* who) const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void AssumeDefaultIfNoInteraction();
protected:
	virtual FScore EvalScoreFor_Implementation(APlayerState* who) const; // = 0
	virtual void AssumeDefaultIfNoInteraction_Implementation(); // = 0

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText displayName;
};
