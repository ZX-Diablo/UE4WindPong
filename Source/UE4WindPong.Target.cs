// Copyright ZX.Diablo 2018

using UnrealBuildTool;
using System.Collections.Generic;

public class UE4WindPongTarget : TargetRules
{
	public UE4WindPongTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "UE4WindPong" } );
	}
}
