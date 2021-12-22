// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"

void ATower::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (Tank) {
		//get dist to tank
		//check if tank is in range
		//if in range rotate turret to tank
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

		if (Distance <= FireRange) {
			RotateTurret(Tank->GetActorLocation());
		}
	}
	
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank =Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
