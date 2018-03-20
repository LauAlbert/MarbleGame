// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUp.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SceneComponent.h"
#include "MyLevelScriptActor.h"
#include "Marble.h"

// Sets default values
APickUp::APickUp()
{
	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	}

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);


	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetupAttachment(MeshComp);
	//SphereComp->OnComponentBeginOverlap.AddDynamic(this, &APickUp::OverlapPickUp);


	PointLightComp = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComp"));
	PointLightComp->SetupAttachment(MeshComp);
	PointLightComp->SetCastShadows(false);

	RotatingMovementComp = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovementComp"));
	

}

//void APickUp::OverlapPickUp(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
//{
//	UE_LOG(LogTemp, Warning, TEXT("HIT"));
//	if (OtherActor != NULL && OverlappedComponent != OtherComp && OtherComp != NULL)
//	{
//		AMarble* Marble = Cast<AMarble>(OtherActor);
//		Marble->AddCoin();
//		Destroy();
//	}
//}

void APickUp::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("HIT"));
	if (OtherActor)
	{
		AMarble* Marble = Cast<AMarble>(OtherActor);
		if (Marble)
		{
			//AMyLevelScriptActor* MyLevel = Cast<AMyLevelScriptActor>(GetWorld()->GetLevelScriptActor());
			//if (MyLevel)
			//{
			//	MyLevel->AddCoin(GetActorLocation());
			//}
			Marble->AddCoin(GetActorLocation());
			Destroy();
		}

	}
}
