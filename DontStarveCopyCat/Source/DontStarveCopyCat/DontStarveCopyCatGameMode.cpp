// Copyright Epic Games, Inc. All Rights Reserved.

#include "DontStarveCopyCatGameMode.h"
#include "DontStarveCopyCatCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADontStarveCopyCatGameMode::ADontStarveCopyCatGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
