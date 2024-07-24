// Copyright@ Shalimov Dmytro 23.04.1991 Kyiv Ukraine

using UnrealBuildTool;
using System.Collections.Generic;

public class ZeusEditorTarget : TargetRules
{
	public ZeusEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("Zeus");
	}
}
