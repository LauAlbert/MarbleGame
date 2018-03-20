// Fill out your copyright notice in the Description page of Project Settings.

#include "MarbleGameGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Public/PickUp.h"
#include "Public/MarbleSaveGame.h"
#include "Marble.h"

AMarbleGameGameModeBase::AMarbleGameGameModeBase()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APickUp::StaticClass(), FoundActors);
	_amountOfCoinsInLevel = FoundActors.Num();
}

//void AMarbleGameGameModeBase::BeginPlay()
//{
//	Super::BeginPlay();
//	SetupLevel();
//	UE_LOG(LogTemp, Warning, TEXT("%d"), _amountOfCoinsInLevel);
//}
//
//void AMarbleGameGameModeBase::SetupLevel()
//{
//	TArray<AActor*> FoundActors;
//	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APickUp::StaticClass(), FoundActors);
//	_amountOfCoinsInLevel = FoundActors.Num();
//}

int AMarbleGameGameModeBase::GetAmountOfCoins()
{
	return _amountOfCoinsInLevel;
}

//int AMarbleGameGameModeBase::GetTime()
//{
//	return 0;
//}

//void AMarbleGameGameModeBase::CompleteLevel(APawn* InstigatorPawn)
//{
//	if (InstigatorPawn)
//	{
//		InstigatorPawn->DisableInput(nullptr);
//		AMarble* Marble = Cast<AMarble>(InstigatorPawn);
//		if (Marble)
//		{
//			UMarbleSaveGame* SaveGameInstance = Cast<UMarbleSaveGame>(UGameplayStatics::CreateSaveGameObject(UMarbleSaveGame::StaticClass()));
//			SaveGameInstance->CoinCollected = Marble->GetCoin();
//			UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveGameInstance->SaveSlotName, SaveGameInstance->UserIndex);
//		}
//
//		OnCompleteLevel.Broadcast(true);
//
//
//	}
//}