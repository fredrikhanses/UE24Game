// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachineBase.h"

// Sets default values
UStateMachineBase::UStateMachineBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryComponentTick.bCanEverTick = bTickEnabled;
}

// Called when the game starts or when spawned
void UStateMachineBase::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentState = NewObject<UState>(this, InitialState->GetFName(), RF_NoFlags, InitialState.GetDefaultObject());
	CurrentState->OnEnterState();
}

// Called every frame
void UStateMachineBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	CurrentState->OnTickState();
}

void UStateMachineBase::ReceiveEvent(FName EventName)
{
	TSubclassOf<UState>* NextStateClass = CurrentState->StateTransitions.Find(EventName);

	if (NextStateClass != nullptr)
	{
		if (CurrentState->GetClass() == *NextStateClass)
		{
			return;
		}

		CurrentState->OnExitState();
		CurrentState = NewObject<UState>(*NextStateClass);
		CurrentState->OnEnterState();
	}
}