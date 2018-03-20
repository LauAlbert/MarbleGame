// Fill out your copyright notice in the Description page of Project Settings.

#include "MyLevelScriptActor.h"
#include "MarbleSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "PickUp.h"
#include "Marble.h"
#include "LevelStuct.h"


void AMyLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();
	OnCompleteLevel.Broadcast(false);
	//SetupLevel();
	//UE_LOG(LogTemp, Warning, TEXT("%d"), AmountOfCoinsInLevel);
}

void AMyLevelScriptActor::SetupLevel()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APickUp::StaticClass(), FoundActors);
	AmountOfCoinsInLevel = FoundActors.Num();
}


AMyLevelScriptActor::AMyLevelScriptActor()
{
	UMarbleSaveGame* LoadGameInstance = Cast<UMarbleSaveGame>(UGameplayStatics::CreateSaveGameObject(UMarbleSaveGame::StaticClass()));
	LoadGameInstance = Cast<UMarbleSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInstance->SaveSlotName, LoadGameInstance->UserIndex));
	//SaveGame = LoadGameInstance;
	PrevCoinCollected = LoadGameInstance->MarbleLevelData.CoinCollected;
	BestTime = LoadGameInstance->MarbleLevelData.BestTime;

	SetupLevel();
}

int32 AMyLevelScriptActor::GetPrevCoinCollected()
{
	return PrevCoinCollected;
}

float AMyLevelScriptActor::GetBestTime()
{
	return BestTime;
}

int32 AMyLevelScriptActor::GetLevel()
{
	return Level;
}

void AMyLevelScriptActor::CompleteLevel(APawn* InstigatorPawn)
{
	if (InstigatorPawn)
	{
		InstigatorPawn->DisableInput(nullptr);
		AMarble* Marble = Cast<AMarble>(InstigatorPawn);
		if (Marble)
		{
			UMarbleSaveGame* SaveGameInstance = Cast<UMarbleSaveGame>(UGameplayStatics::CreateSaveGameObject(UMarbleSaveGame::StaticClass()));


			SaveGameInstance->MarbleLevelData.CoinCollected = (Marble->GetCoin() > PrevCoinCollected) ? Marble->GetCoin() : PrevCoinCollected;
			SaveGameInstance->MarbleLevelData.BestTime = (UGameplayStatics::GetTimeSeconds(GetWorld()) < BestTime) ? UGameplayStatics::GetTimeSeconds(GetWorld()) : BestTime;

			UE_LOG(LogTemp, Warning, TEXT("GameSave"));
			UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveGameInstance->SaveSlotName, SaveGameInstance->UserIndex);
		}

		OnCompleteLevel.Broadcast(true);


	}
}

int AMyLevelScriptActor::GetAmountOfCoinsInLevel()
{
	return AmountOfCoinsInLevel;
}



