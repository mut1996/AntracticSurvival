// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ASGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ANTARCTICSURVIVAL_API UASGameInstance : public UGameInstance
{
	GENERATED_BODY()

private :
	// 플레이어 캐릭터 객체를 나타냅니다.
	class APlayerCharacter* PlayerCharacter;

public :
	// 플레이어 캐릭터 객체를 반환합니다.
	class APlayerCharacter* GetPlayerCharacter();

	
};
