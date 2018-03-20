// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Marble.generated.h"

class USpringArmComponent;
class UCameraComponent;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCoinCollectedSignature, int, CoinAmount, const TArray<FVector>&, CoinLocation,  FVector, NewCoinLocation);

UCLASS()
class MARBLEGAME_API AMarble : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMarble();

protected:


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Ball)
	UStaticMeshComponent* Ball;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Ball)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Ball)
	UCameraComponent* Camera;

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;



	void MoveRight(float Val);
	void MoveForward(float Val);

	void Jump();

private:

	int32 CoinCollected;


	TArray<FVector> CoinCollectedLocation;

public:	


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool bCanJump;
	
	UPROPERTY(EditAnywhere, Category=Ball)
	float RollTorque;

	UPROPERTY(EditAnywhere, Category=Ball)
	float JumpImpulse;

	UFUNCTION(BlueprintCallable, Category=Ball)
	void AddCoin(FVector CoinLocation);
	UFUNCTION(BlueprintPure, Category = Ball)
	int GetCoin();

	UFUNCTION(BlueprintCallable, Category = Ball)
	void StopMovement();

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnCoinCollectedSignature OnCoinCollect;

};
