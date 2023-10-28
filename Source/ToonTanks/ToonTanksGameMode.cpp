// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "ToonTanksPlayerController.h"

void AToonTanksGameMode::DestroyActor(AActor* DeadActor) {

	if (Tank == DeadActor) {
		Tank->HandleDestruction();
		if (ToonTanksPlayerController) {
			ToonTanksPlayerController->SetPlayerEnabledState(false);
		}
		EndGame(false);
	}
	else if (ATower* DestroyTower = Cast<ATower>(DeadActor)) {
		DestroyTower->HandleDestruction();
		--TargetTower;
		if (TargetTower == 0) {
			EndGame(true);
		}
	}
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	TimerHandleStart();

}

void AToonTanksGameMode::TimerHandleStart() {
	
	TargetTower = GetTargetTowerCount();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	if (ToonTanksPlayerController) {

		StartGame();

		ToonTanksPlayerController->SetPlayerEnabledState(false);

		FTimerHandle TimerHandle;
		FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(ToonTanksPlayerController, &AToonTanksPlayerController::SetPlayerEnabledState, true);
		GetWorldTimerManager().SetTimer(TimerHandle, TimerDelegate, StartDelay, false);
	}
}

int AToonTanksGameMode::GetTargetTowerCount() {

	TArray<AActor*> Tower;

	UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Tower);

	return Tower.Num();
}