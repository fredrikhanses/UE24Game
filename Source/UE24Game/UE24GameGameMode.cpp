// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UE24GameGameMode.h"
#include "UE24GameHUD.h"
#include "UE24GameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE24GameGameMode::AUE24GameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUE24GameHUD::StaticClass();
}
