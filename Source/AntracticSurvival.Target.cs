// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class AntracticSurvivalTarget : TargetRules
{
	public AntracticSurvivalTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "AntracticSurvival" } );
	}
}
