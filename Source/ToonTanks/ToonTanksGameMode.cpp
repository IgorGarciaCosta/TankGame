// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Tank.h"
#include "Tower.h"
#include "ToonTanksPlayerController.h"
#include "Kismet/GameplayStatics.h"


void AToonTanksGameMode::BeginPlay() {
	Super::BeginPlay();
	HandleGameStart();
	
}

void AToonTanksGameMode::ActorDied(AActor* DeadActor) {
	if (DeadActor == Tank) {
		Tank->HandleDestruction();
		if (ToonTanksPlayerController){
			ToonTanksPlayerController->SetPlayerEnableState(false);
			Tank->DisableInput(Tank->GetTankPlayerController());
			Tank->GetTankPlayerController()->bShowMouseCursor = false;
		}
		
	}

	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor)) {
		DestroyedTower->HandleDestruction();
	}
}

void AToonTanksGameMode::HandleGameStart()
{
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	if (ToonTanksPlayerController) {
		ToonTanksPlayerController->SetPlayerEnableState(false);

		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(ToonTanksPlayerController, &AToonTanksPlayerController::SetPlayerEnableState, true);
		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, PlayerEnableTimerDelegate,StartDelay,false);

	}
}
