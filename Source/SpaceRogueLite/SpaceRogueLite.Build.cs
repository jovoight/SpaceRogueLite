// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SpaceRogueLite : ModuleRules
{
	public SpaceRogueLite(ReadOnlyTargetRules target) : base(target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange([
			"Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput",
			"GameplayAbilities", "GameplayTags", "GameplayTasks"
		]);
	}
}