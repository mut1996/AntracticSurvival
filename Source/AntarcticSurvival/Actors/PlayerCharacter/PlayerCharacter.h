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
	// �÷��̾� ��Ʈ�ѷ��� ��Ÿ���ϴ�.
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
	// ������Ʈ ������ �ʱ�ȭ
	void InitializeComponents();

	// ������� �Ծ��� ��� ȣ��� �޼���
	UFUNCTION()
	void OnHit(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, 
		class AController* InstigatedBy, AActor* DamageCauser);
	/// - DamagedActor : ������� ���� ���͸� ��Ÿ���ϴ�.
	/// - Damage : ���� ���ظ� ��Ÿ���ϴ�.
	/// - DamageType : ����� Ÿ���� ���޵˴ϴ�.
	/// - InstigatedBy : ���ظ� �� ��Ʈ�ѷ��� ���޵˴ϴ�.
	/// - DamageCauser : ���ظ� �� ���Ͱ� ���޵˴ϴ�.

public :
	FORCEINLINE class AGamePlayerController* GetPlayerController() const
	{ return PlayerController; }

	



};
