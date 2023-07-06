// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/WeakObjectPtr.h"
#include "ObjectiveViewRepresentation.generated.h"


UENUM(BlueprintType)
enum class EObjectiveState : uint8
{
	Failed        UMETA(DisplayName = "Failed"),
	NoInteraction UMETA(DisplayName = "No Interaction"),
	Completed     UMETA(DisplayName = "Completed")
};


class UObjective;


USTRUCT(BlueprintType)
struct PROCEDURALSANDWICH_API FObjectiveViewRepresentation
{
	GENERATED_BODY()

public:
	FObjectiveViewRepresentation();
	~FObjectiveViewRepresentation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText displayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EObjectiveState displayState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TWeakObjectPtr<UObjective> dataSource;
};
