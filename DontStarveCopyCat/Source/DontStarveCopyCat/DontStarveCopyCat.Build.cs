// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DontStarveCopyCat : ModuleRules
{
	public DontStarveCopyCat(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
