// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!ControlledTank || !PlayerTank) { return; };

	//TODO Move towards the player

	//Aim towards the player
	ControlledTank->AimAt(PlayerTank->GetTargetLocation());

	// Fire every frame
	ControlledTank->Fire(); // TODO limit firing rate
}
