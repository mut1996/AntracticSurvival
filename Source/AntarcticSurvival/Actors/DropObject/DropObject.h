// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AntarcticSurvival.h"
#include "GameFramework/Actor.h"
#include "../../Enums/DropObjectType.h"

#include "DropObject.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API ADropObject : public AActor
{
	GENERATED_BODY()
	
private :
	// ������Ʈ Ÿ���� ��Ÿ���ϴ�.
	EDropObjectType ObjectType;

	// �������� �ӷ��� ��Ÿ���ϴ�.
	float FallDownSpeed;

	// �÷��̾�� ���� ������� ��Ÿ���ϴ�.
	float ChangeHungryValue;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class URotatingMovementComponent * RotatingMovement;

	// �÷��̾� ��ü�� ��Ÿ���ϴ�.
	class APlayerCharacter* PlayerCharacter;

public:	
	ADropObject();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void InitializeDropObject(EDropObjectType objType, float changeHungryValue,
		class UStaticMesh* staticMesh, class APlayerCharacter* playerCharacter);

private :
	void InitializeComponents();

	// �������� �������� �����մϴ�.
	void FallDown(float dt);

	UFUNCTION()
	void AddDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
	/// - OverlappedComponent : ��ģ �ڽ��� ������Ʈ�� ��Ÿ���ϴ�.
	/// - OtherActor : ��ģ ��� ���͸� ��Ÿ���ϴ�.
	/// - OtherComp : ��ģ ��� ������Ʈ�� ��Ÿ���ϴ�.
	/// - OtherBodyIndex : bMultibodyOverlap �� true �� ���
	///   ���� �ø����� ������ ��� �ø������� �����ϱ� ���� ��ȣ
	/// - bFromSweep : ���Ͱ� �̵��� �� Sweep �̺�Ʈ�� �߻���Ű���� �Ͽ� 
	///   �߻��� �̺�Ʈ������ ��Ÿ���ϴ�.
	/// - SweepResult : Sweep �̺�Ʈ �߻��� �ڼ��� ����� ��� �ִ� �����Ͱ� ���޵˴ϴ�.
};
