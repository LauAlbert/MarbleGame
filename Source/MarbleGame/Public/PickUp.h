// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

class USphereComponent;
class URotatingMovementComponent;
class UPointLightComponent;

UCLASS()
class MARBLEGAME_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PickUp)
	UStaticMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PickUp)
	USphereComponent* SphereComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PickUp)
	URotatingMovementComponent* RotatingMovementComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PickUp)
	UPointLightComponent* PointLightComp;

public:
	
	//void OverlapPickUp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
