// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum class ERoundState : uint8
{
	PreRound        UMETA(DisplayName="Pre-round"),
	RoundInProgress UMETA(DisplayName="Round (in progress)"),
	RoundOvertime   UMETA(DisplayName="Round (overtime)"),
	Summary         UMETA(DisplayName="Post-round summary")
};
