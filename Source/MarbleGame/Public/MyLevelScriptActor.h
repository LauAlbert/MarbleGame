// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MyLevelScriptActor.generated.h"

class UMarbleSaveGame;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCompleteLevel, bool, LevelComplete);
/**
 * 
 */
UCLASS()
class MARBLEGAME_API AMyLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

private:
	int32 PrevCoinCollected;

	int32 AmountOfCoinsInLevel;

	float BestTime;

	//UMarbleSaveGame* SaveGame;

public:
	AMyLevelScriptActor();

	virtual void BeginPlay() override;

	void SetupLevel();

	UPROPERTY(EditDefaultsOnly, Category = LevelSettings)
	int32 Level;

	UPROPERTY(EditDefaultsOnly, Category = LevelSettings)
	int32 CoinCollected;

	UPROPERTY(EditDefaultsOnly, Category = LevelSettings)
	TArray<FVector> CoinCollectedLocation;

	UFUNCTION(BlueprintCallable)
	int GetPrevCoinCollected();

	UFUNCTION(BlueprintCallable)
	float GetBestTime();

	UFUNCTION(BlueprintCallable)
	void CompleteLevel(APawn* InstigatorPawn);

	UFUNCTION(BlueprintCallable)
	int32 GetAmountOfCoinsInLevel();

	UFUNCTION(BlueprintCallable)
	int32 GetLevel();

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnCompleteLevel OnCompleteLevel;

};
