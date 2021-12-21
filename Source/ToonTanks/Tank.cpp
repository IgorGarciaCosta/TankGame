// Fill out your copyright notice in the Description page of Project Settings.



#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"

ATank::ATank() {

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	

}

void ATank::MoveForward(float Value)
{
	//GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("Value: %f"), Value));
	FVector DeltaLocation = FVector::ZeroVector;
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	DeltaLocation.X = Value*Speed*DeltaTime;
	AddActorLocalOffset(DeltaLocation);
}

void ATank::MoveRight(float Value)
{
	FVector DeltaLocation = FVector::ZeroVector;
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	DeltaLocation.Y = Value * Speed * DeltaTime;
	AddActorLocalOffset(DeltaLocation);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ATank::MoveRight);
}
