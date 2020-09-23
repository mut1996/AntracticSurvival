#include "HorizontalMovementComponent.h"
#include "../../Actors/PlayerCharacter/PlayerCharacter.h"
#include "../../Actors/PlayerController/Game/GamePlayerController.h"

UHorizontalMovementComponent::UHorizontalMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHorizontalMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// 플레이어 객체 얻기
	PlayerCharacterInst = Cast<APlayerCharacter>(GetOwner());
}

void UHorizontalMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 왼쪽 / 오른쪽 이동
	HorizontalMovement();
}

void UHorizontalMovementComponent::HorizontalMovement()
{
	float axis = PlayerCharacterInst->GetPlayerController()->GetHorizontalInputValue();

	// 플레이어 캐릭터를 특정한 방향으로 이동시킵니다.
	PlayerCharacterInst->AddMovementInput(
		FVector::RightVector * -axis);
}

