// Fill out your copyright notice in the Description page of Project Settings.


#include "ASGameInstance.h"
#include "../Actors/PlayerCharacter/PlayerCharacter.h"

APlayerCharacter* UASGameInstance::GetPlayerCharacter()
{
	// 만약 PlayerCharacter 가 유효하지 않을 경우 PlayerCharacter 객체를 찾습니다.
	if (!IsValid(PlayerCharacter))
	{
		// 찾은 액터를 저장할 리스트
		TArray<AActor*> outActors;

		// APlayerCharacter 클래스 형태의 객체를 월드에서 찾습니다.
		UGameplayStatics::GetAllActorsOfClass(
			GetWorld(), APlayerCharacter::StaticClass(), outActors);
		/// - GetAllActorsOfClass() : 특정한 형태의 액터를 월드에서 찾습니다.

		// 찾은 액터를 APlayerCharacter 형식으로 캐스팅합니다.
		PlayerCharacter = Cast<APlayerCharacter>(outActors[0]);
	}

	return PlayerCharacter;
}
