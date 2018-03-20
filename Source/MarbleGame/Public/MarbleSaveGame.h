// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "LevelStuct.h"
#include "MarbleSaveGame.generated.h"

//struct FSaveStruct;
/**
 * 
 */
UCLASS()
class MARBLEGAME_API UMarbleSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, Category = Basic)
	FSaveStruct MarbleLevelData;



	UPROPERTY(VisibleAnywhere, Category = Basic)
		FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
		uint32 UserIndex;

	UMarbleSaveGame();
	
};
