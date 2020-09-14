// Fill out your copyright notice in the Description page of Project Settings.


// GitHub

#pragma once

#include "AntracticSurvival.h"
#include "Components/ActorComponent.h"
#include "FloatingMovementComponent.generated.h"

/// - UHT �� ���� �ڵ����� �����ȴ� �ΰ����� 
/// - �ش��� include �� ���� �ϴܿ� �ۼ��մϴ�. 

// UCLASS()
/// - �ش� Ŭ������ UObject ���� �����մϴ�. 

// ANTRACTICSURVIVAL_API : �ܺ� ��⿡�� ���� ���θ� ���մϴ�.

// UFloatingMovementComponent 
/// - Ŭ���� �̸� 
/// - U : UObject ������ Ŭ������ ���˴ϴ�. 
/// - F : �Ϲ�Ŭ���� / ����ü�� �ٴ� ���λ��Դϴ�. 
/// - A : Actor Ŭ������ ��۹޴¤� Ŭ�������� ���˴ϴ�. 
/// - I : Unreal Interface class �� ���˴ϴ� .
/// - E : enum, enumClass 

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ANTRACTICSURVIVAL_API UFloatingMovementComponent : public UActorComponent
{
	GENERATED_BODY()
	/// - �׻� Ŭ���� ���R���� �ۼ��Ǿ� �� �ϸ�, 
	/// Ŭ������ ������ �ʿ��� ������ �����ϵ��� �մϴ�.

private: 
	// �⺻���� ������� (0.0f) 
	// EditAnywhere : �������� ������ â���� ������ ��������  �ǹ��մϴ�. 
	// VisibleAnywhere :  �������� ������ â���� �б� �������� ���˴ϴ�.
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcess = "true"))
	float FloatingSpeed;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcess = "true"))
	float FloatingValue; 

	// ��� �������� �����ΰ� ó�� ǥ���� �������� ��Ÿ���ϴ�.
	float StartTime;

	// ������ �ʱ� ��ġ�� ������ ���� 
	FVector ActorBegineinLocation;

public:	
	// �ش� Ŭ������ �⺻�Ӽ��� �����մϴ�. 
	 
	UFloatingMovementComponent();

protected:
	// ������ ���۵� ���� �����Ǿ��� ��� �� �� ȣ��˴ϴ�. 

	virtual void BeginPlay() override;

public:	
	// �� �����Ӹ��� ȣ��˴ϴ�. 
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
