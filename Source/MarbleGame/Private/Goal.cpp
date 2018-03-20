// Fill out your copyright notice in the Description page of Project Settings.

#include "Goal.h"
#include "Components/DecalComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "MarbleGameGameModeBase.h"
#include "MyLevelScriptActor.h"
#include "Marble.h"

// Sets default values
AGoal::AGoal()
{
	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	}

	GoalLightMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GoalLightMeshComp"));
	GoalLightMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GoalLightMeshComp->SetupAttachment(RootComponent);

	GoalBannerMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GoalBannerMeshComp"));
	GoalBannerMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GoalBannerMeshComp->SetupAttachment(RootComponent);

	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	DecalComp->SetupAttachment(RootComponent);


	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetupAttachment(RootComponent);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AGoal::OverlapGoal);

}

void AGoal::OverlapGoal(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("GAME OVER"));
	if (OtherActor != NULL && OverlappedComponent != OtherComp && OtherComp != NULL)
	{
		AMarble* Marble = Cast<AMarble>(OtherActor);
		if (Marble)
		{
			Marble->StopMovement();
			AMyLevelScriptActor* MyLevel = Cast<AMyLevelScriptActor>(GetWorld()->GetLevelScriptActor());
			//AMarbleGameGameModeBase* GM = Cast<AMarbleGameGameModeBase>(GetWorld()->GetAuthGameMode());
			if (MyLevel)
			{
				MyLevel->CompleteLevel(Marble);
			}
		}
	}
}