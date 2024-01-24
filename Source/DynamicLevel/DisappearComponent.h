// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "DisappearComponent.generated.h"

UCLASS(Blueprintable)
class DYNAMICLEVEL_API UDisappearComponent : public UActorComponent
{
	GENERATED_BODY()

  public:
	// Sets default values for this component's properties
	UDisappearComponent();

  protected:
	// Called when the game starts
	virtual void BeginPlay() override;

  public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRoom1Change);
	UPROPERTY(BlueprintAssignable, Category = "Disappear")
	FOnRoom1Change OnRoom1Change;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRoom2Change);
	UPROPERTY(BlueprintAssignable, Category = "Disappear")
	FOnRoom2Change OnRoom2Change;

  private:
	APlayerController* PlayerController = nullptr;
	AActor* Owner = nullptr;
	APawn* PlayerCharacter = nullptr;
};
