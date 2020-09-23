// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AntarcticSurvival.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()


private :
	// 플레이어 컨트롤러를 나타냅니다.
	class AGamePlayerController* PlayerController;

	UPROPERTY(VisibleAnywhere)
	class UHorizontalMovementComponent* HorizontalMovement;


public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



private :
	// 컴포넌트 데이터 초기화
	void InitializeComponents();

	// 대미지를 입었을 경우 호출될 메서드
	UFUNCTION()
	void OnHit(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, 
		class AController* InstigatedBy, AActor* DamageCauser);
	/// - DamagedActor : 대미지를 입은 액터를 나타냅니다.
	/// - Damage : 입은 피해를 나타냅니다.
	/// - DamageType : 대미지 타입이 전달됩니다.
	/// - InstigatedBy : 피해를 준 컨트롤러가 전달됩니다.
	/// - DamageCauser : 피해를 준 액터가 전달됩니다.

public :
	FORCEINLINE class AGamePlayerController* GetPlayerController() const
	{ return PlayerController; }

	



};
