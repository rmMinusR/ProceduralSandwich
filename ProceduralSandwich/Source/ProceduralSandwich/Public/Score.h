// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Score.generated.h"

/**
 * Depending on context, represents either the player's current score, or a change to the player's score.
 */
USTRUCT(BlueprintType)
struct PROCEDURALSANDWICH_API FScore
{
	GENERATED_BODY();

public:
	FScore();
	~FScore();

	UPROPERTY()
	float annoyance;

	UPROPERTY()
	float promotion;

	FScore operator+(const FScore& rhs) const;
	FScore& operator+=(const FScore& rhs);
};
