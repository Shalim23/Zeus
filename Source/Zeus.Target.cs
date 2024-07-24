// Copyright@ Shalimov Dmytro 23.04.1991 Kyiv Ukraine

using UnrealBuildTool;
using System.Collections.Generic;

public class ZeusTarget : TargetRules
{
	public ZeusTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("Zeus");
	}
}
