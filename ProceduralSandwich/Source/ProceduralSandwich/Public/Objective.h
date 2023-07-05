// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Score.h"
#include "Objective.generated.h"


UENUM(BlueprintType)
enum class EObjectiveState : uint8
{
	Failed        UMETA( DisplayName="Failed" ),
	NoInteraction UMETA( DisplayName="No Interaction" ),
	Completed     UMETA( DisplayName="Completed" )
};


class APlayerState;


UCLASS( Abstract, Blueprintable, ClassGroup=(Custom) )
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

public:
	UFUNCTION(BlueprintPure)
	EObjectiveState GetState() const;

	UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	FScore EvalScoreFor(APlayerState* who) const;
protected:
	virtual FScore EvalScoreFor_Implementation(APlayerState* who) const; // = 0

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText displayName;
};
