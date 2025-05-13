// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaceRogueLiteGameMode.h"
#include "Player/SpaceRogueLitePlayerController.h"
#include "UObject/ConstructorHelpers.h"

ASpaceRogueLiteGameMode::ASpaceRogueLiteGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ASpaceRogueLitePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/SpaceRogueLite/Blueprints/BP_PlayerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	} 

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(
		TEXT("/Game/SpaceRogueLite/Blueprints/BP_SpaceRogueLitePlayerController"));
	if (PlayerControllerBPClass.Class != nullptr)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}
