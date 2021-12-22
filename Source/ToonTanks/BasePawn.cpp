// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Engine/Engine.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootSceneComponent;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	//RootComponent = Capsule;
	Capsule->SetupAttachment(RootSceneComponent);

	

	//create static mesh component
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	BaseMesh->SetupAttachment(RootSceneComponent);
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpperBody"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnPoint"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	
	TurretMesh->SetWorldRotation(LookAtRotation);
}
