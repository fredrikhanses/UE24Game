// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "State.h"
#include "StateMachineBase.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent, Blueprintable, BlueprintType))
class UE24GAME_API UStateMachineBase : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this component's properties
	UStateMachineBase();

	UPROPERTY(EditAnywhere, Category = "Ticking")
		bool bTickEnabled = true;

	UPROPERTY(EditAnywhere, Category = "States")
		TSubclassOf<UState> InitialState = UState::StaticClass();

	UPROPERTY(EditAnywhere, Category = "States")
		TMap<FName, UState*> StateTransitioins = TMap<FName, UState*>();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UState* CurrentState = nullptr;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void ReceiveEvent(FName EventName);
};
