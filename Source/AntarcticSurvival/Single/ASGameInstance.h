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
	// �÷��̾� ĳ���� ��ü�� ��Ÿ���ϴ�.
	class APlayerCharacter* PlayerCharacter;

public :
	// �÷��̾� ĳ���� ��ü�� ��ȯ�մϴ�.
	class APlayerCharacter* GetPlayerCharacter();

	
};
