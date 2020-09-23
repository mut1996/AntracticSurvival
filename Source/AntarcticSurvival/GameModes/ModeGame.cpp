// Fill out your copyright notice in the Description page of Project Settings.


#include "ModeGame.h"

#include "../Actors/PlayerCharacter/PlayerCharacter.h"
#include "../Actors/PlayerController/Game/GamePlayerController.h"

AModeGame::AModeGame()
{
	static ConstructorHelpers::FClassFinder<APlayerCharacter> DEFAULT_PLAYER_PAWN(
		TEXT("Blueprint'/Game/Resources/Blueprints/BP_PlayerCharacter.BP_PlayerCharacter_C'"));

	/// FClassFinder : UClass �� ������ �� ����մϴ�.
	/// UClass �� ���� �� ��� �� �ڿ� _C �� �ۼ��մϴ�.
	if (DEFAULT_PLAYER_PAWN.Succeeded())
	{
		DefaultPawnClass = DEFAULT_PLAYER_PAWN.Class;
	}

	PlayerControllerClass = AGamePlayerController::StaticClass();
	/// - ClassType::StaticClass() : �ش� Ŭ������ UClass �� ����ϴ�.
}