// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"
#include "Projectile.h"
#include "Camera/CameraShakeBase.h"
#include "Components/CapsuleComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

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

void ABasePawn::HandleDestruction()
{
	//visual/sound effects
	if (DeathParticles) {
		UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticles, GetActorLocation(), GetActorRotation());
		if (DeathSound) {
			UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());

		}
		if (DeathCameraShakeClass) {
			GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShakeClass);
		}
	}
}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	
	TurretMesh->SetWorldRotation(LookAtRotation);
}

void ABasePawn::Fire() {
	//DrawDebugSphere(GetWorld(), ProjectileSpawnPoint->GetComponentLocation(), 25.f, 12, FColor::Blue, false, 3.f);
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation());
	Projectile->SetOwner(this);
}
