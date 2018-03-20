// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MarbleGameGameModeBase.generated.h"


//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCompleteLevel, bool, LevelComplete);
/**
 * 
 */
UCLASS()
class MARBLEGAME_API AMarbleGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	
	AMarbleGameGameModeBase();

	//virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	int GetAmountOfCoins();

	//UFUNCTION(BlueprintCallable)
	//int GetTime();

	//UFUNCTION(BlueprintCallable)
	//void CompleteLevel(APawn* InstigatorPawn);

	//UPROPERTY(BlueprintAssignable, Category = "Events")
	//FOnCompleteLevel OnCompleteLevel;

private:
	int _amountOfCoinsInLevel;


	//UFUNCTION(BlueprintCallable)
	//void SetupLevel();
	

	
};
