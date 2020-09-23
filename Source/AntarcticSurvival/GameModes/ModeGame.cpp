// Fill out your copyright notice in the Description page of Project Settings.


#include "ModeGame.h"

#include "../Actors/PlayerCharacter/PlayerCharacter.h"
#include "../Actors/PlayerController/Game/GamePlayerController.h"

AModeGame::AModeGame()
{
	static ConstructorHelpers::FClassFinder<APlayerCharacter> DEFAULT_PLAYER_PAWN(
		TEXT("Blueprint'/Game/Resources/Blueprints/BP_PlayerCharacter.BP_PlayerCharacter_C'"));

	/// FClassFinder : UClass 를 가져올 때 사용합니다.
	/// UClass 를 얻을 때 경로 맨 뒤에 _C 를 작성합니다.
	if (DEFAULT_PLAYER_PAWN.Succeeded())
	{
		DefaultPawnClass = DEFAULT_PLAYER_PAWN.Class;
	}

	PlayerControllerClass = AGamePlayerController::StaticClass();
	/// - ClassType::StaticClass() : 해당 클래스의 UClass 를 얻습니다.
}