// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LevelStuct.generated.h"

USTRUCT(BlueprintType)
struct FSaveStruct
{
	GENERATED_BODY()

	FSaveStruct() : CoinCollected(0), BestTime(0.0f), bHasCompleted(false) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="struct")
	int32 CoinCollected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "struct")
	float BestTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "struct")
	bool bHasCompleted;
};
