#include "PlayerCharacterAnimInst.h"

#include "../Actors/PlayerCharacter/PlayerCharacter.h"
#include "../Actors/PlayerController/Game/GamePlayerController.h"

void UPlayerCharacterAnimInst::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	// 애니메이션을 소유하는 Pawn 을 얻습니다.
	PlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());
}

void UPlayerCharacterAnimInst::NativeUpdateAnimation(float dt)
{
	Super::NativeUpdateAnimation(dt);

	// 에디터에서도 해당 메서드는 호출되므로 PlayerCharacter 가 유효하지 않다면 실행시키지 않습니다.
	if (!IsValid(PlayerCharacter)) return;

	HorizontalSpeed = FMath::Abs(
		PlayerCharacter->GetPlayerController()->GetHorizontalInputValue());
}