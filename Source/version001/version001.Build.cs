// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class version001 : ModuleRules
{
    public version001(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput" // <-- 🔥 ESTA LÍNEA ES CLAVE
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
