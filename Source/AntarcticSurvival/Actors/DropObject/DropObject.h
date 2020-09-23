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
	// 오브젝트 타입을 나타냅니다.
	EDropObjectType ObjectType;

	// 떨어지는 속력을 나타냅니다.
	float FallDownSpeed;

	// 플레이어에게 가할 대미지를 나타냅니다.
	float ChangeHungryValue;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class URotatingMovementComponent * RotatingMovement;

	// 플레이어 객체를 나타냅니다.
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

	// 떨어지는 움직임을 구현합니다.
	void FallDown(float dt);

	UFUNCTION()
	void AddDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
	/// - OverlappedComponent : 겹친 자신의 컴포넌트를 나타냅니다.
	/// - OtherActor : 겹친 상대 액터를 나타냅니다.
	/// - OtherComp : 겹친 상대 컴포넌트를 나타냅니다.
	/// - OtherBodyIndex : bMultibodyOverlap 이 true 일 경우
	///   여러 컬리전과 겹쳤을 경우 컬리전들을 구분하기 위한 번호
	/// - bFromSweep : 액터가 이동할 때 Sweep 이벤트를 발생시키도록 하여 
	///   발생한 이벤트인지를 나타냅니다.
	/// - SweepResult : Sweep 이벤트 발생시 자세한 결과를 담고 있는 데이터가 전달됩니다.
};
