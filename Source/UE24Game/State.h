// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "State.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UE24GAME_API UState : public UObject
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Category = "State Handlers")
        TMap<FName, TSubclassOf<UState>> StateTransitions = TMap<FName, TSubclassOf<UState>>();

    UFUNCTION(BlueprintNativeEvent, Category = "State Handlers")
        void OnEnterState();
        void OnEnterState_Implementation() {};

    UFUNCTION(BlueprintNativeEvent, Category = "State Handlers")
        void OnTickState();
        void OnTickState_Implementation() {};

    UFUNCTION(BlueprintNativeEvent, Category = "State Handlers")
        void OnExitState();
        void OnExitState_Implementation() {};
};
