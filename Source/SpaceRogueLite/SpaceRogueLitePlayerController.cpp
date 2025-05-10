// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaceRogueLitePlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

ASpaceRogueLitePlayerController::ASpaceRogueLitePlayerController()
{
	bShowMouseCursor = true;
}

void ASpaceRogueLitePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Sub = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Sub->AddMappingContext(MappingContext, 0);
	}
}

