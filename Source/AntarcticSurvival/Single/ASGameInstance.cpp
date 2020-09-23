// Fill out your copyright notice in the Description page of Project Settings.


#include "ASGameInstance.h"
#include "../Actors/PlayerCharacter/PlayerCharacter.h"

APlayerCharacter* UASGameInstance::GetPlayerCharacter()
{
	// ���� PlayerCharacter �� ��ȿ���� ���� ��� PlayerCharacter ��ü�� ã���ϴ�.
	if (!IsValid(PlayerCharacter))
	{
		// ã�� ���͸� ������ ����Ʈ
		TArray<AActor*> outActors;

		// APlayerCharacter Ŭ���� ������ ��ü�� ���忡�� ã���ϴ�.
		UGameplayStatics::GetAllActorsOfClass(
			GetWorld(), APlayerCharacter::StaticClass(), outActors);
		/// - GetAllActorsOfClass() : Ư���� ������ ���͸� ���忡�� ã���ϴ�.

		// ã�� ���͸� APlayerCharacter �������� ĳ�����մϴ�.
		PlayerCharacter = Cast<APlayerCharacter>(outActors[0]);
	}

	return PlayerCharacter;
}
