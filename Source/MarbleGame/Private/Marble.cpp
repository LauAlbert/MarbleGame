// Fill out your copyright notice in the Description page of Project Settings.

#include "Marble.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
AMarble::AMarble()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MarbleMesh(TEXT("StaticMesh'/Game/Blueprints/Marble/MarbleMesh.MarbleMesh'"));

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


	Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MarbleMesh"));
	Ball->SetStaticMesh(MarbleMesh.Object);
	Ball->SetSimulatePhysics(true);
	Ball->SetAngularDamping(1.f);
	Ball->SetLinearDamping(1.f);
	Ball->BodyInstance.MassScale = 3.5f;
	Ball->BodyInstance.MaxAngularVelocity = 800.0f;
	Ball->SetNotifyRigidBodyCollision(true);


	RootComponent = Ball;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = true;

	SpringArm->TargetArmLength = 800.0f;
	SpringArm->RelativeRotation = FRotator(45.0f, 0.0f, 0.0f);

	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bEnableCameraLag = false;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
	
	RollTorque = 50000000.0f;
	JumpImpulse = 350000.0f;
	bCanJump = true;
	CoinCollected = 0;

}



void AMarble::NotifyHit(UPrimitiveComponent * MyComp, AActor * Other, UPrimitiveComponent * OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult & Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	bCanJump = true;
}

void AMarble::Jump()
{
	if (bCanJump)
	{
		Ball->AddImpulse(FVector(0.0f, 0.0f, JumpImpulse));
		bCanJump = false;
	}
}

// Called to bind functionality to input
void AMarble::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMarble::Jump);

	PlayerInputComponent->BindAxis("MoveRight", this, &AMarble::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMarble::MoveForward);

	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);


}

void AMarble::MoveRight(float Val)
{
	if ((Controller != NULL) && (Val != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		
		const FVector Torque = Direction * Val * 4000.0f;

		Ball->AddForce(Torque, NAME_None, true);
	}
}

void AMarble::MoveForward(float Val)
{
	if ((Controller != NULL) && (Val != 0.0f))
	{
	
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		const FVector Torque = Direction * Val * 4000.0f;

		Ball->AddForce(Torque, NAME_None, true);

	}

}

void AMarble::AddCoin(FVector CoinLocation)
{
	CoinCollected++;
	CoinCollectedLocation.Add(CoinLocation);
	UE_LOG(LogTemp, Warning, TEXT("%d"), CoinCollected);
	OnCoinCollect.Broadcast(CoinCollected, CoinCollectedLocation, CoinLocation);
}

int AMarble::GetCoin()
{
	return CoinCollected;
}

void AMarble::StopMovement()
{
	Ball->SetLinearDamping(2.0f);
}