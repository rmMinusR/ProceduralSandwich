// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Score.h"
#include "ProceduralSandwichGameState.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALSANDWICH_API AProceduralSandwichGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FScore currentScore;
};
