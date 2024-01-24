// Fill out your copyright notice in the Description page of Project Settings.

#include "DisappearComponent.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UDisappearComponent::UDisappearComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You
	// can turn these features off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UDisappearComponent::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = GetWorld()->GetFirstPlayerController();
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController not found"));
		return;
	}

	Owner = GetOwner();
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("Owner not found"));
		return;
	}

	PlayerCharacter = PlayerController->GetPawn();
	if (!PlayerCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerCharacter not found"));
		return;
	}
}

// Called every frame
void UDisappearComponent::TickComponent(float DeltaTime, ELevelTick TickType,
										FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto Yaw = PlayerCharacter->GetActorRotation().Yaw;
	if (Yaw < -150.f)
	{
		OnRoom1Change.Broadcast();
	}

	auto XPos = PlayerCharacter->GetActorLocation().X;
	if (XPos >= 700.f)
	{
		OnRoom2Change.Broadcast();
	}
}
