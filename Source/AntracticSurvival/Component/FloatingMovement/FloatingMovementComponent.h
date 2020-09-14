// Fill out your copyright notice in the Description page of Project Settings.


// GitHub

#pragma once

#include "AntracticSurvival.h"
#include "Components/ActorComponent.h"
#include "FloatingMovementComponent.generated.h"

/// - UHT 에 의해 자동으로 생성된느 부가파일 
/// - 해더의 include 문 제일 하단에 작성합니다. 

// UCLASS()
/// - 해당 클래스가 UObject 임을 선언합니다. 

// ANTRACTICSURVIVAL_API : 외부 모듈에의 공개 여부를 뜻합니다.

// UFloatingMovementComponent 
/// - 클래스 이름 
/// - U : UObject 형태의 클래스에 사용됩니다. 
/// - F : 일반클래스 / 구조체에 붙는 접두사입니다. 
/// - A : Actor 클래스를 상송받는ㄴ 클래ㅐ스에 사용됩니다. 
/// - I : Unreal Interface class 에 사용됩니다 .
/// - E : enum, enumClass 

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ANTRACTICSURVIVAL_API UFloatingMovementComponent : public UActorComponent
{
	GENERATED_BODY()
	/// - 항상 클래스 ㅊ첮술에 작성되어 야 하며, 
	/// 클래스가 엔진에 필요한 인프라를 지원하돌고 합니다.

private: 
	// 기본값을 보장받은 (0.0f) 
	// EditAnywhere : 에디터의 디테일 창에서 편집이 가능함을  의미합니다. 
	// VisibleAnywhere :  에디터의 디테일 창에서 읽기 전용으로 사용됩니다.
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcess = "true"))
	float FloatingSpeed;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcess = "true"))
	float FloatingValue; 

	// 어느 시점부터 움직인것 처럼 표현할 것인지를 나타냅니다.
	float StartTime;

	// 액터의 초기 위치를 저장할 변수 
	FVector ActorBegineinLocation;

public:	
	// 해당 클래스의 기본속성을 정의합니다. 
	 
	UFloatingMovementComponent();

protected:
	// 게임이 시작될 떄나 스폰되었을 경우 한 번 호출됩니다. 

	virtual void BeginPlay() override;

public:	
	// 매 프레임마다 호출됩니다. 
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
