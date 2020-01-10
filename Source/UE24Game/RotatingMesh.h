// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageableInterface.h"
#include "Engine/StaticMeshActor.h"
#include "RotatingMesh.generated.h"

/**
 * 
 */
UCLASS()
class UE24GAME_API ARotatingMesh : public AStaticMeshActor, public IDamageableInterface
{
	GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation Speed")
    FRotator RotationPerSecond = FRotator(0.0f, 90.0f, 0.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float CurrentHealth = 10.0f;

    ARotatingMesh();

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

    virtual float ApplyDamage_Implementation(float InDamage) override;

    virtual float GetCurrentHealth() override;

};
