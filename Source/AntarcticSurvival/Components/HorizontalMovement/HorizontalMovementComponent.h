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
	// 해당 컴포넌트를 소유하는 APLayerCharacter 객체를 나타냅니다.
	class APlayerCharacter* PlayerCharacterInst;

public:	
	UHorizontalMovementComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, 
		FActorComponentTickFunction* ThisTickFunction) override;


private :
	// 수평 이동
	void HorizontalMovement();
		
};
