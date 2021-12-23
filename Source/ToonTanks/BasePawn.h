// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleDestruction();
protected:
	UFUNCTION()
		void RotateTurret(FVector LookAtTarget);
	UFUNCTION()
		void Fire();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "tank", meta = (AllowPrivateAccess = "true"))
		class USceneComponent* RootSceneComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "tank", meta = (AllowPrivateAccess = "true"))
		class USceneComponent* ProjectileSpawnPoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "tank", meta = (AllowPrivateAccess = "true"))
		 UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "tank", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "tank", meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent* Capsule;
	UPROPERTY(EditDefaultsOnly, Category = "projectile")
	TSubclassOf<class AProjectile>ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	class UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category = "Projectile")
		class USoundBase* DeathSound;



};
