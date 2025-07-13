// Copyright Epic Games, Inc. All Rights Reserved.

#include "GridInventoryCPPGameMode.h"
#include "GridInventoryCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGridInventoryCPPGameMode::AGridInventoryCPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
