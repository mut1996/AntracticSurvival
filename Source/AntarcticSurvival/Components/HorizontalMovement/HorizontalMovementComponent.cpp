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

	// �÷��̾� ��ü ���
	PlayerCharacterInst = Cast<APlayerCharacter>(GetOwner());
}

void UHorizontalMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ���� / ������ �̵�
	HorizontalMovement();
}

void UHorizontalMovementComponent::HorizontalMovement()
{
	float axis = PlayerCharacterInst->GetPlayerController()->GetHorizontalInputValue();

	// �÷��̾� ĳ���͸� Ư���� �������� �̵���ŵ�ϴ�.
	PlayerCharacterInst->AddMovementInput(
		FVector::RightVector * -axis);
}

