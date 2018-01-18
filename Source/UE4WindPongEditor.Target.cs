// Copyright ZX.Diablo 2018

using UnrealBuildTool;
using System.Collections.Generic;

public class UE4WindPongEditorTarget : TargetRules
{
	public UE4WindPongEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "UE4WindPong" } );
	}
}
