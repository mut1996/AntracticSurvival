// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HorizontalMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ANTARCTICSURVIVAL_API UHorizontalMovementComponent : public UActorComponent
{
	GENERATED_BODY()

private :
	// �ش� ������Ʈ�� �����ϴ� APLayerCharacter ��ü�� ��Ÿ���ϴ�.
	class APlayerCharacter* PlayerCharacterInst;

public:	
	UHorizontalMovementComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, 
		FActorComponentTickFunction* ThisTickFunction) override;


private :
	// ���� �̵�
	void HorizontalMovement();
		
};
