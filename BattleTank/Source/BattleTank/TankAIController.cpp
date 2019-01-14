// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a Tank!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s!!"), *(ControlledTank->GetName()));
	}
	
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not found!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController: %s found by %s!!"), *(PlayerTank->GetName()), *(ControlledTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!GetControlledTank()) { return; }

	GetControlledTank()->AimAt(GetPlayerTank()->GetTargetLocation());
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
