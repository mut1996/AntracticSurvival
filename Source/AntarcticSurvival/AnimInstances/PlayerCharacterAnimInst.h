// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacterAnimInst.generated.h"

/**
 * 
 */
UCLASS()
class ANTARCTICSURVIVAL_API UPlayerCharacterAnimInst : public UAnimInstance
{
	GENERATED_BODY()

private :
	class APlayerCharacter* PlayerCharacter;

protected :
	UPROPERTY(BlueprintReadOnly)
	float HorizontalSpeed;
	/// - BlueprintReadOnly : �������Ʈ Ŭ�������� �б� �������� ����� �� �ֽ��ϴ�.
	/// - BlueprintReadWrite : �������Ʈ Ŭ�������� �а� ���Ⱑ ���������ϴ�.

public :
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float dt) override;


	
};
