#include "PlayerCharacterAnimInst.h"

#include "../Actors/PlayerCharacter/PlayerCharacter.h"
#include "../Actors/PlayerController/Game/GamePlayerController.h"

void UPlayerCharacterAnimInst::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	// �ִϸ��̼��� �����ϴ� Pawn �� ����ϴ�.
	PlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());
}

void UPlayerCharacterAnimInst::NativeUpdateAnimation(float dt)
{
	Super::NativeUpdateAnimation(dt);

	// �����Ϳ����� �ش� �޼���� ȣ��ǹǷ� PlayerCharacter �� ��ȿ���� �ʴٸ� �����Ű�� �ʽ��ϴ�.
	if (!IsValid(PlayerCharacter)) return;

	HorizontalSpeed = FMath::Abs(
		PlayerCharacter->GetPlayerController()->GetHorizontalInputValue());
}