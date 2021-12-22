// Fill out your copyright notice in the Description page of Project Settings.



#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "DrawDebugHelpers.h"

ATank::ATank() {

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef = Cast<APlayerController>(GetController());
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerControllerRef) {
		FHitResult HitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 25.f, 12, FColor::Red, false, -1.f);
	}

}

void ATank::MoveForward(float Value)
{
	//GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("Value: %f"), Value));
	FVector DeltaLocation = FVector::ZeroVector;
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	DeltaLocation.X = Value*Speed*DeltaTime;
	AddActorLocalOffset(DeltaLocation, true);
}

void ATank::MoveRight(float Value)
{
	FRotator DeltaRotation = FRotator::ZeroRotator;
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	DeltaRotation.Yaw = Value* DeltaTime * TurnRate;
	AddActorLocalRotation(DeltaRotation);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ATank::MoveRight);
}
