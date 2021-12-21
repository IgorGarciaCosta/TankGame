// Fill out your copyright notice in the Description page of Project Settings.



#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "Engine.h"
#include "GameFramework/SpringArmComponent.h"

ATank::ATank() {

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);


}

void ATank::Move(float Value)
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("Value: %f"), Value));
	FVector DeltaLocation(0.f);
	DeltaLocation.X = Value;
	AddActorLocalOffset(DeltaLocation);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);

}
