// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Goal.generated.h"

class UDecalComponent;
class UBoxComponent;

UCLASS()
class MARBLEGAME_API AGoal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoal();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Goal)
	UDecalComponent* DecalComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Goal)
	UStaticMeshComponent* GoalBannerMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Goal)
	UStaticMeshComponent* GoalLightMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Goal)
	UBoxComponent* BoxComp;

	

public:	

	UFUNCTION()
	void OverlapGoal(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	
};
