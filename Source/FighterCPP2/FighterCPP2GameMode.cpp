// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "FighterCPP2.h"
#include "FighterCPP2GameMode.h"
#include "FighterCPP2HUD.h"
#include "FighterCPP2Character.h"

AFighterCPP2GameMode::AFighterCPP2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFighterCPP2HUD::StaticClass();
}
