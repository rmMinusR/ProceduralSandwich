// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Score.h"
#include "ObjectivesSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALSANDWICH_API UObjectivesSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FScore currentScore;
};
